#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * This function initializes a simple shell loop that continuously prompts
 * the user for input, reads the command entered, executes it, and frees
 * allocated memory for the command. The loop runs indefinitely until the
 * program is terminated.
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
		execute_command(command);
		free(command);
	}
	return (0);
}
