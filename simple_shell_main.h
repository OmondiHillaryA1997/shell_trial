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
#include <stdarg.h>

/* CONSTANT */
#define MAX_STDIN_SIZE 1024
#define MAX_ARG_SIZE 64
#define MAX_NUM_ARGS 32
#define BUFFER_SIZE 1024
#define MAX_ARGUMENTS 64
#define MAX_INPUT_LENGTH 1024
#define INITIAL_BUFFER_SIZE 64
/*CUSTOMIZED FUNCTIONS*/
/* Custom printf function
void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Determine the length of the formatted string
    va_list args_copy;
    va_copy(args_copy, args);
    int length = vsnprintf(NULL, 0, format, args_copy);
    va_end(args_copy);

    // Allocate memory for the formatted string
    char *formatted_string = (char *)malloc(length + 1); // +1 for the null terminator
    if (formatted_string == NULL) {
        va_end(args);
        return; // Memory allocation failed
    }

    // Format the string
    vsnprintf(formatted_string, length + 1, format, args);

    // Output the formatted string
    write(STDOUT_FILENO, formatted_string, length);

    // Clean up
    free(formatted_string);
    va_end(args);
}*/

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
/*void my_printf(const char *format, ...);*/
size_t my_strlen(const char *str);

/* CLOSING GUARD */
#endif
