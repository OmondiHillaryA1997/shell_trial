#include "simple_shell_main.h"

/**
 * my_strcmp - function that customizes strcmp
 * @str1: argument 1
 * @str2: argument 2
 *
 * Return: success(0)
 *
 */

int my_strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 == *str2)
		return (0); /* Strings are equal */
	else if (*str1 < *str2)
	{
		return (-1); /* str1 is lexicographically less than str2*/
	}
		return (1); /* str1 is lexicographically greater than str2*/
}

/**
 * handle_command - function that executes a command
 * @command: argument 1
 *
 * Return (0)
 */

void handle_command(char *command)
{
	char *argv[100]; /* An array to hold command and arguments*/

	/* Split the input into arguments*/
	int num_tokens = 0;
	char *token = strtok(command, " ");
	int status;

	while (token != NULL)
	{
		argv[num_tokens] = token;
		token = strtok(NULL, " ");
		num_tokens++;
	}
	argv[num_tokens] = NULL;

	/* Handle the 'exit' command using custom strcmp*/
	if (my_strcmp(argv[0], "exit") == 0)
	{
		printf("Exiting shell...\n");
		exit(0);
	}

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork error");
		exit(1);
	} else if (child_pid == 0)
	{
		/* Child process*/
		char *envp[] = { NULL }; /* An empty environment for simplicity*/

		if (execve(argv[0], argv, envp) == -1)
		{
			perror("Execve error");
			exit(1);
		}
	} else
	{
		waitpid(child_pid, &status, 0);/*wait for the child process to finish*/
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		{
			printf("Command executed\n");
		} else
		{
			printf("%s: No such file or directory\n", argv[0]);
		}
	}
}
