#include "simple_shell_main.h"

void execute_input_buff(char *argv[]) {
    pid_t chi_pid = fork();
    if (chi_pid == -1) {
        perror("Fork error");
        exit(1);
    } else if (chi_pid == 0) { // Child process
        // Replace the current process image with a new one
        execve(argv[0], argv, NULL);
        // If execve fails, it will reach here
        perror("Execve error");
        exit(1);
    } else { // Parent process
        int status;
        // Wait for the child process to finish
        waitpid(chi_pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            printf("Command executed successfully\n");
        } else {
            printf("Command failed to execute\n");
        }
    }
}

