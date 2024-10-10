#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

// Define a maximum command length
#define MAX_COMMAND_LENGTH 1024

// Function prototypes for built-in commands
void shell_help();
void shell_exit();
void shell_pwd();
void shell_cd(char *path);

int main() {
    char command[MAX_COMMAND_LENGTH];  // Command buffer
    char *args[100];  // Array to hold arguments (up to 100 arguments)
    
    // Main shell loop
    while (1) {
        printf("shell> ");  // Display the shell prompt
        fgets(command, MAX_COMMAND_LENGTH, stdin);  // Get user input
        command[strcspn(command, "\n")] = 0;  // Remove the newline character

        // Skip empty input
        if (strlen(command) == 0) {
            continue;
        }

        // Tokenize the command into args
        int i = 0;
        args[i] = strtok(command, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        // Check for built-in commands
        if (strcmp(args[0], "help") == 0) {
            shell_help();
        } else if (strcmp(args[0], "exit") == 0) {
            shell_exit();
        } else if (strcmp(args[0], "pwd") == 0) {
            shell_pwd();
        } else if (strcmp(args[0], "cd") == 0) {
            shell_cd(args[1]);
        } else {
            printf("Unknown command: %s\n", args[0]);
        }
    }

    return 0;
}

// Help command - prints out available commands
void shell_help() {
    printf("Available commands:\n");
    printf("help - Display this help message\n");
    printf("exit - Exit the shell\n");
    printf("pwd - Print the current working directory\n");
    printf("cd [path] - Change the directory to the specified path\n");
}

// Exit command - terminates the shell
void shell_exit() {
    printf("Exiting shell...\n");
    exit(0);
}

// Pwd command - prints the current working directory
void shell_pwd() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("getcwd() error");
    }
}

// Cd command - changes the current working directory
void shell_cd(char *path) {
    if (path == NULL) {
        fprintf(stderr, "cd: missing argument\n");
    } else {
        if (chdir(path) != 0) {
            perror("cd failed");
        }
    }
}