#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
* read_line - Simple shell to read and print user input
*
* Return: Always 0
*/

int read_line(void)
{
	char *line;

	size_t size;
	ssize_t nread;

	line = NULL;
	size = 0;
	while (1)
	{
		nread = getline(&line, &size, stdin);

		if (nread == -1)
		{
			break;
		}
		printf("%s", line);
	}
	free(line);
	return (0);
}
