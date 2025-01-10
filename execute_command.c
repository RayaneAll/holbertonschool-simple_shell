#include "shell.h"

/**
 * execute_command - Executes a command using execve.
 * @command: The command to execute, as a string.
 *
 * This function parses the command, checks its accessibility,
 * and uses fork to create a child process to execute it.
 *
 * Return: 0 on success, 1 if the command is invalid or cannot be executed.
 */
int execute_command(char *command)
{
	char *argv[100];

	command[strcspn(command, "\n")] = '\0';

	if (command == NULL || strlen(command) == 0)
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
