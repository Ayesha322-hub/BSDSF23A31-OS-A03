#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // for chdir()

// Read command from user
char* read_cmd(char* prompt, FILE* fp) {
    printf("%s", prompt);
    char* cmdline = (char*) malloc(sizeof(char) * MAX_LEN);
    int c, pos = 0;

    while ((c = getc(fp)) != EOF) {
        if (c == '\n') break;
        cmdline[pos++] = c;
    }

    if (c == EOF && pos == 0) {
        free(cmdline);
        return NULL; // Handle Ctrl+D
    }
    
    cmdline[pos] = '\0';
    return cmdline;
}

// Tokenize command line into arguments
char** tokenize(char* cmdline) {
    char** tokens = malloc(sizeof(char*) * MAX_LEN);
    char* token = strtok(cmdline, " \t\n");
    int pos = 0;

    while (token != NULL) {
        tokens[pos++] = token;
        token = strtok(NULL, " \t\n");
    }
    tokens[pos] = NULL;  // null-terminate
    return tokens;
}

// Handle built-in commands
int handle_builtin(char** arglist) {
    if (arglist[0] == NULL) return 0; // skip empty commands

    if (strcmp(arglist[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(arglist[0], "cd") == 0) {
        if (arglist[1] == NULL) {
            fprintf(stderr, "cd: missing argument\n");
        } else if (chdir(arglist[1]) != 0) {
            perror("cd");
        }
        return 1;
    } else if (strcmp(arglist[0], "help") == 0) {
        printf("Built-in commands:\n");
        printf("cd <directory>\nexit\nhelp\njobs\n");
        return 1;
    } else if (strcmp(arglist[0], "jobs") == 0) {
        printf("Job control not yet implemented.\n");
        return 1;
    }

    return 0; // not a built-in
}

