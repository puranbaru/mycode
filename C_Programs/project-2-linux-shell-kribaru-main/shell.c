#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
#include "helpers.h"
#include "helpers.c"

#define MAX_COMMAND_LENGTH 1024

// function prototypes
void shell_help();
void shell_exit();
void shell_pwd();
void shell_cd(char *path);
char* resolve_path(char* command);

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

        // parse function tokenizes the command input
        char *line = strdup(cmd);  
        char **args = parse(line, " "); 

        // if the command is invalid or tokenization failed, 
        // free memory and continue
        if (args == NULL) {
            free(line);
            continue;
        }
        // tokenize command into args
        int i = 0;
        args[i] = strtok(cmd, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
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
            // handle other functions w/ fork and execv
            pid_t pid = fork();  
            if (pid == 0) {
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

        // free allocated memory
        free(args);
        free(line);
    }

    return 0;
}

// help command: print out available commands
void shell_help() {
    printf("Available commands:\n");
    printf("pwd - Print the current working directory\n");
    printf("cd [path] - Change the directory to the specified path\n");
    printf("help - Display this help message\n");
    printf("exit - Exit the shell\n");
    
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
    // if command already has full path, return same command
    if (command[0] == '/') {
        return command;
    }

    // get PATH environment variable
    char* path_env = getenv("PATH");
    if (path_env == NULL) {
        return NULL; 
    }

    // tokenize PATH var by colon :
    char* path = strtok(path_env, ":");
    while (path != NULL) {
        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, command);

        // check if file exists + if it's executable
        if (access(full_path, X_OK) == 0) {
            return strdup(full_path); 
        }

       
        path = strtok(NULL, ":");
    }

    return NULL;  
}