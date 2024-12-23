#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
* execute_command - Executes a command using execve
* @command: The command to execute
*
* Description: This function takes command as input and attempts to execute it
* by creating a child process with fork(). The child process uses execve() to
* replace its image with the specified executable. If the command is invalid
* or the execution fails, appropriate error messages are displayed.
*
* Return: Always 0 on success, 1 if command is invalid or cannot be executed.
*/

int execute_command(char *command)
{
	char *argv[2];

	pid_t pid;
	int status;

	if (command == NULL || strlen(command) == 0)
		return (1);

	if (access(command, X_OK) == -1)
	{
		perror("./shell");
		return (1);
	}

	argv[0] = command;
	argv[1] = NULL;

	pid = fork();
	if (pid == 0)
	{
		if (execve(command, argv, NULL) == -1)
		{
			perror("./shell");
			_exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		perror("fork");
	}

	return (0);
}
