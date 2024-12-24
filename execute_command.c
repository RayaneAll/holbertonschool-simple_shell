#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

/**
* execute_command - Executes a command using execve
* @command: The command to execute
*
* Return: 0 on success, 1 if command is invalid or cannot be executed.
*/

int execute_command(char *command)
{
	char *argv[2];

	pid_t pid;
	int status;

	/* Trim newline from command */
	command[_strcspn(command, "\n")] = '\0';

	if (command == NULL || _strlen(command) == 0)
		return (1);

	if (access(command, X_OK) == -1)
	{
		perror("./shell");
		return (1);
	}

	argv[0] = command;
	argv[1] = NULL;

	pid = fork();
	if (pid == 0) /* Child process */
	{
		if (execve(command, argv, environ) == -1)
		{
			perror("./shell");
			_exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0) /* Parent process */
	{
		wait(&status);
	}
	else /* Fork failed */
	{
		perror("fork");
	}

	return (0);
}
