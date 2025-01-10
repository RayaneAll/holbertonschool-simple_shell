#include "shell.h"

/**
 * execute_fork - Creates a child process to execute a command.
 * @argv: Array of strings containing the command arguments.
 *
 * This function uses fork to create a child process. In the child process,
 * execve is used to execute the command. The parent process waits for
 * the child process to finish.
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
