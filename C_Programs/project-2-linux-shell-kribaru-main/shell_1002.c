#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
#include <fcntl.h>  // Added for file handling
#include "helpers.h"
#include "helpers.c"

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 128  // Added for argument limit in command parsing

// function prototypes
void shell_help();
void shell_exit();
void shell_pwd();
void shell_cd(char *path);
char* resolve_path(char* command);
void execute_command(char **args, char *input_file, char *output_file);  // New function prototype for execution with redirection
void execute_piped_commands(char *cmd1, char *cmd2);  // New function prototype for piped commands
void parse_command(char *input, char **args, char **input_file, char **output_file);  // New function prototype for parsing

int main() {
    char cmd[MAX_COMMAND_LENGTH];  // command buffer
    
    while (1) {
        printf("shell> ");  
        fgets(cmd, MAX_COMMAND_LENGTH, stdin);  
        cmd[strcspn(cmd, "\n")] = 0;  

        // skip empty input
        if (strlen(cmd) == 0) {
            continue;
        }

        // Handling pipes
        char *pipe_position = strchr(cmd, '|');
        if (pipe_position != NULL) {
            *pipe_position = '\0';
            char *cmd1 = cmd;
            char *cmd2 = pipe_position + 1;
            execute_piped_commands(cmd1, cmd2);
            continue;
        }

        // parse function tokenizes the command input
        char *line = strdup(cmd);  
        char **args = malloc(MAX_ARGS * sizeof(char*));  // Memory allocation for args
        char *input_file = NULL;
        char *output_file = NULL;

        parse_command(line, args, &input_file, &output_file);

        // if the command is invalid or tokenization failed, 
        if (args[0] == NULL) {
            free(line);
            free(args);
            continue;
        }

        // check for built-in commands
        if (strcmp(args[0], "cd") == 0) {
            shell_cd(args[1]);
        } else if (strcmp(args[0], "pwd") == 0) {
            shell_pwd();
        } else if (strcmp(args[0], "help") == 0) {
            shell_help();
        } else if (strcmp(args[0], "exit") == 0) {
            shell_exit();
        } else {
            // handle other functions w/ fork and execv using redirection
            execute_command(args, input_file, output_file);
        }

        // free allocated memory
        free(args);
        free(line);
    }

    return 0;
}

// function to parse commands including redirection
void parse_command(char *input, char **args, char **input_file, char **output_file) {
    *input_file = NULL;
    *output_file = NULL;
    int i = 0;

    char *token = strtok(input, " \t\n");
    while (token != NULL) {
        if (strcmp(token, "<") == 0) {
            token = strtok(NULL, " \t\n");
            if (token != NULL) *input_file = token;
        } else if (strcmp(token, ">") == 0) {
            token = strtok(NULL, " \t\n");
            if (token != NULL) *output_file = token;
        } else {
            args[i++] = token;
        }
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
}

// function to execute a command with possible redirection
void execute_command(char **args, char *input_file, char *output_file) {
    pid_t pid = fork();
    if (pid == 0) { // Child process
        if (input_file) {
            int fd_in = open(input_file, O_RDONLY);
            if (fd_in < 0) {
                perror("Error opening input file");
                exit(EXIT_FAILURE);
            }
            dup2(fd_in, STDIN_FILENO);
            close(fd_in);
        }

        if (output_file) {
            int fd_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd_out < 0) {
                perror("Error opening output file");
                exit(EXIT_FAILURE);
            }
            dup2(fd_out, STDOUT_FILENO);
            close(fd_out);
        }

        char* program_path = resolve_path(args[0]);
        if (program_path != NULL) {
            execv(program_path, args);
            perror("execv failed");
            exit(EXIT_FAILURE);
        } else {
            fprintf(stderr, "Command not found: %s\n", args[0]);
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
    } else {
        perror("fork failed");  // handle fork failure
    }
}

// function to execute commands with pipes
void execute_piped_commands(char *cmd1, char *cmd2) {
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    if (fork() == 0) { // First child - Executes cmd1
        dup2(pipe_fd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
        close(pipe_fd[0]); // Close read end
        close(pipe_fd[1]);
        
        char *args[MAX_ARGS];
        parse_command(cmd1, args, NULL, NULL);
        execvp(args[0], args);
        perror("execvp failed for cmd1");
        exit(EXIT_FAILURE);
    }

    if (fork() == 0) { // Second child - Executes cmd2
        dup2(pipe_fd[0], STDIN_FILENO); // Redirect stdin to pipe read end
        close(pipe_fd[1]); // Close write end
        close(pipe_fd[0]);

        char *args[MAX_ARGS];
        parse_command(cmd2, args, NULL, NULL);
        execvp(args[0], args);
        perror("execvp failed for cmd2");
        exit(EXIT_FAILURE);
    }

    close(pipe_fd[0]);
    close(pipe_fd[1]);
    wait(NULL);
    wait(NULL);
}

// help command: print out available commands
void shell_help() {
    printf("Available commands:\n");
    printf("pwd - Print the current working directory\n");
    printf("cd [path] - Change the directory to the specified path\n");
    printf("help - Display this help message\n");
    printf("exit - Exit the shell\n");
    printf("Supports I/O Redirection with '>' and '<' and piping with '|'.\n");
}

// exit command: terminate the shell
void shell_exit() {
    printf("Exiting shell...\n");
    exit(0);
}

// pwd command: print working directory
void shell_pwd() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("getcwd() error");
    }
}

// cd command: change current directory
void shell_cd(char *path) {
    if (path == NULL) {
        fprintf(stderr, "cd: missing argument\n");
    } else {
        if (chdir(path) != 0) {
            perror("cd failed");
        }
    }
}

char* resolve_path(char* command) {
    if (command[0] == '/') {
        return command;
    }

    char* path_env = getenv("PATH");
    if (path_env == NULL) {
        return NULL; 
    }

    char* path = strtok(path_env, ":");
    while (path != NULL) {
        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, command);

        if (access(full_path, X_OK) == 0) {
            return strdup(full_path); 
        }
        path = strtok(NULL, ":");
    }
    return NULL;  
}