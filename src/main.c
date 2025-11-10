#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        char* cmdline = read_cmd("myshell> ", stdin);
        if (cmdline == NULL) break;  // Ctrl+D

        char** args = tokenize(cmdline);
        if (!handle_builtin(args)) {
            execute(args);  // call external commands
        }

        free(cmdline);
        free(args);
    }

    return 0;
}
