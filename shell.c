#include "shell.h"

/**
* main - Entry point of the shell program
*
* @argc: Argument count (unused)
* @argv: Argument vector (unused)
* @envp: Environment variables
*
* Return: Always 0 (success)
*/
int main(int argc, char *argv[], char *envp[])
{
	char *command;

	(void)argc;
	(void)argv;

	while (1)
	{
		display_shell();
		command = read_line();
		if (command == NULL)
		{
			continue;
		}
		execute_command(command, envp);
		free(command);
	}

	return (0);
}
