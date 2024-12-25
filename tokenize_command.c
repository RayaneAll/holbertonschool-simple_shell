#include "shell.h"
#include <string.h>

/**
* tokenize_command - Tokenizes the command string into arguments.
* @command: The command string to tokenize.
* @argv: The array to store arguments.
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
