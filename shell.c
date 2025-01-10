#include "shell.h"

/**
 * main - Entry point of the shell program.
 *
 * This function initializes an infinite loop to run the shell.
 * In each iteration, it displays the prompt, reads a command,
 * and executes the command. It also handles memory for
 * each user-entered command.
 *
 * Return: Always 0 (success).
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

		if (strcmp(command, "exit\n") == 0)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}

		execute_command(command);
		free(command);
	}

	return (0);
}
