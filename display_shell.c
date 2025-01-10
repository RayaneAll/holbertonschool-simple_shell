#include "shell.h"

/**
 * display_shell - Displays the shell prompt.
 *
 * This function prints a custom prompt "$ " to invite the user
 * to input a command. It takes no arguments and returns nothing.
 */
void display_shell(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
	}
}
