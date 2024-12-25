#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
* execute_command - Executes a command using execve
* @command: The command to execute
*
* Return: 0 on success, 1 if command is invalid or cannot be executed.
*/
int execute_command(char *command)
{
	char *argv[100];

	command[_strcspn(command, "\n")] = '\0';

	if (command == NULL || _strlen(command) == 0)
		return (1);

	tokenize_command(command, argv);

	if (access(argv[0], X_OK) == -1)
	{
		perror("./shell");
		return (1);
	}

	execute_fork(argv);
	return (0);
}
