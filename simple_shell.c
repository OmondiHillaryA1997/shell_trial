#include "simple_shell_main.h"



// Custom strlen function
size_t my_strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int my_strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    if (*str1 == *str2) {
        return 0; // Strings are equal
    } else if (*str1 < *str2) {
        return -1; // str1 is lexicographically less than str2
    } else {
        return 1; // str1 is lexicographically greater than str2
    }
}

void handle_command(char *command) {
    char *argv[100];
    int num_tokens = 0;
    char *token = strtok(command, " ");

    while (token != NULL) {
        argv[num_tokens] = token;
        token = strtok(NULL, " ");
        num_tokens++;
    }
    argv[num_tokens] = NULL;

    if (my_strcmp(argv[0], "exit") == 0) {
        char exit_message[] = "Exiting shell...\n";
        write(STDOUT_FILENO, exit_message, my_strlen(exit_message));
        exit(0);
    }

    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("Fork error");
        exit(1);
    } else if (child_pid == 0) {
        char *envp[] = { NULL };
        if (execve(argv[0], argv, envp) == -1) {
            char execve_error[] = "Execve error\n";
            write(STDERR_FILENO, execve_error, my_strlen(execve_error));
            exit(1);
        }
    } else {
        int status;
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            char success_message[] = "Command executed successfully\n";
            write(STDOUT_FILENO, success_message, my_strlen(success_message));
        } else {
            char error_message[] = "No such file or directory\n";
            write(STDERR_FILENO, error_message, my_strlen(error_message));
        }
    }
}
