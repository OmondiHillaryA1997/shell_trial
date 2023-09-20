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
#define MAX_STDIN_SIZE 1024
#define MAX_ARG_SIZE 64
#define MAX_NUM_ARGS 32
#define BUFFER_SIZE 1024
#define MAX_ARGUMENTS 64
#define MAX_INPUT_LENGTH 1024
#define INITIAL_BUFFER_SIZE 64


/* PROTOTYPES */
int my_strcmp(const char *str1, const char *str2);
void handle_command(char *command);
void handle_input_buff(char *command);
void execute_command(char *command, char *args[]);
char *custom_getline();
int custom_strcmp(const char *s1, const char *s2);
void split_arguments(char *input, char **arguments);
void custom_strcpy(char *dest, const char *src);
int custom_atoi(const char *str);
void handle_setenv(char **arguments);
void handle_unsetenv(char **arguments);
void custom_cd();
int custom_strlen(const char *str);

/* CLOSING GUARD */
#endif
