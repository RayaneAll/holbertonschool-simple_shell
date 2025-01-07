#include "shell.h"

/**
* read_line - Simple shell to read user input
*
* Return: Pointer to the user input string
*/

char *read_line(void)
{
	char *line = NULL;

	size_t size = 0;

	if (getline(&line, &size, stdin) == -1) /* Handle EOF (Ctrl+D) */
	{
		free(line);
		exit(0);
	}
	return (line); /* Return the input for execution */
}
