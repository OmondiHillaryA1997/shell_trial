#include "simple_shell_main.h"

int main() {
    char *prompt = "#Sshell$ ";
    size_t n = 0;
    ssize_t nchars_read;
    char *input = NULL;

    while (1) {
        printf("%s", prompt);
        nchars_read = getline(&input, &n, stdin);

        if (nchars_read == -1) {
            printf("Exiting shell...\n");
            break;
        }

        // Remove the newline character at the end
        if (input[nchars_read - 1] == '\n') {
            input[nchars_read - 1] = '\0';
        }

        handle_command(input);
    }

    // Free dynamically allocated memory
    free(input);

    return 0;
}
