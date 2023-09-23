// main.c

#include "simple_shell_main.h"


//Custom printf function
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
}
int main() {
    char *prompt = "#Sshell$ ";
    size_t n = 0;
    ssize_t nchars_read;
    char *input = NULL;

    while (1) {
        my_printf("%s", prompt);
        nchars_read = getline(&input, &n, stdin);

        if (nchars_read == -1) {
            my_printf("Exiting shell...\n");
            break;
        }

        if (input[nchars_read - 1] == '\n') {
            input[nchars_read - 1] = '\0';
        }

        handle_command(input);
    }

    free(input);
    return 0;
}
