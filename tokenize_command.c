#include "shell.h"

/**
 * tokenize_command - Splits a command into arguments.
 * @command: String containing the command to split.
 * @argv: Array to store the arguments.
 *
 * This function uses `strtok` to divide a string into multiple
 * substrings using a space (`" "`) as the delimiter.
 * The arguments are stored in an array passed by reference.
 * The array is terminated with a NULL pointer.
 */
void tokenize_command(char *command, char **argv)
{
	char *token;
	int i = 0;

	token = strtok(command, " ");
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}

	argv[i] = NULL;
}
