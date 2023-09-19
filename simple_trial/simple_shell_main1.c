int main(int argc, char **argv) {
    char *prompt = "simple_shell$ ";
    char *input = NULL;
    size_t input_size = 0;

    while (1) {
        printf("%s", prompt);

        ssize_t nchars_read = getline(&input, &input_size, stdin);

        if (nchars_read == -1) {
            printf("Exiting shell....\n");
            free(input); // Free the dynamically allocated input buffer
            break; // Exit on Ctrl+D (EOF)
        }

        // Remove trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Check if the input contains only one word (no spaces)
        char *token = strtok(input, " ");
        if (token == NULL || strtok(NULL, " ") != NULL) {
            printf("Error: Invalid input\n");
            continue; // Display prompt again
        }

        // Execute the command
        if (system(input) == -1) {
            printf("Error: Command not found\n");
        }
    }

    return EXIT_SUCCESS;
}

