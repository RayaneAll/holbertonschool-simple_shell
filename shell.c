#include "shell.h"
#include <stdlib.h>

/**
* main - Entry point of the shell program
*
* Return: Always 0 (success)
*/

int main(void)
{
	char *command;

	while (1)
	{
		display_shell();
		command = read_line();
		if (command == NULL)
			continue;

		execute_command(command);
		free(command);
	}
	return (0);
}
