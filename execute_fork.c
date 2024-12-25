#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
* execute_fork - Forks a process and executes a command.
* @argv: The arguments for the command.
*/
void execute_fork(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./shell");
			_exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		perror("fork");
	}
}
