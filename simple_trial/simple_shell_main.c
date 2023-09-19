#include "simple_shell_main.h"

int main() {
    char *prompt = "(Sshell) $ ";
    size_t n = 0;
    ssize_t numchars_R;
    char *input_buff = NULL;
    char *argv[2]; // We only need space for the command and NULL terminator

    while (1) {
        printf("%s", prompt);
        numchars_R = getline(&input_buff, &n, stdin);

        if (numchars_R == -1) {
            printf("Exiting shell...\n");
            break;
        }

        // Remove the newline character at the end
        if (input_buff[numchars_R - 1] == '\n') {
            input_buff[numchars_R - 1] = '\0';
        }

        // Set up the arguments for execve
        argv[0] = input_buff;
        argv[1] = NULL;

        execute_command(argv);
    }

    // Free dynamically allocated memory
    free(input_buff);

    return 0;
}
