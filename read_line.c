#include "shell.h"

/**
 * read_line - Reads a line of user input in the shell.
 *
 * This function uses getline to read a line from standard input.
 * It also handles end-of-file (EOF) by freeing memory and exiting
 * the program gracefully.
 *
 * Return: Pointer to a string containing the user input.
 *         Returns NULL if an error occurs.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t nread;

	nread = getline(&line, &size, stdin);

	if (nread == -1)
	{
		free(line);
		exit(0);
	}

	return (line);
}
