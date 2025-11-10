#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>   // for FILE, printf, stdin
#include <stdlib.h>  // for malloc, exit

#define MAX_LEN 1024  // maximum length of command line

// Function prototypes
char* read_cmd(char* prompt, FILE* fp);
char** tokenize(char* cmdline);
int handle_builtin(char** arglist);
int execute(char* arglist[]);

#endif
