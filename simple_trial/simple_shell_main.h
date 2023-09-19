/* OPENING GUARD */

#ifndef SIMPLE_SHELL_MAIN_H
#define SIMPLE_SHELL_MAIN_H

/* HEADER */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* CONSTANT */
/*#define MAX_STDIN_SIZE 1024*/


/* PROTOTYPES */
void execute_input_buff(char *argv[]);



/* CLOSING GUARD */
#endif
