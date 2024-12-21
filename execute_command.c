#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
* execute_command - Exemple use of function execve
*
* Description: Program use function execve for replace a
* courant processus by a new executable
*
* Return: Always 0, except if execve fail.
*/
int execute_command(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	return (0);
}
