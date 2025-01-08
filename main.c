#include "main.h"

/**
 * execute_command - Creates a child process to execute a command
 * @array: Array of command arguments
 */
void execute_command(char **array)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Failed to create process");
		free(array);
		exit(41);
	}

	if (child_pid == 0)
	{
		if (execve(array[0], array, NULL) == -1)
		{
			perror("Failed to execute command");
			free(array);
			exit(97);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * parse_input - Reads and tokenizes user input
 * @buf: Buffer to store user input
 * @count: Pointer to size of the buffer
 * Return: Tokenized array of strings
 */
char **parse_input(char *buf, size_t *count)
{
	ssize_t nread;
	char *token, **array;
	int i;

	write(STDOUT_FILENO, "MyShell$ ", 9);
	nread = getline(&buf, count, stdin);
	if (nread == -1)
	{
		perror("Exiting shell");
		free(buf);
		exit(1);
	}

	token = strtok(buf, " \n");
	array = malloc(sizeof(char *) * 1024);
	if (!array)
	{
		perror("Memory allocation failed");
		free(buf);
		exit(1);
	}

	i = 0;
	while (token)
	{
		array[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	array[i] = NULL;

	return (array);
}

/**
 * main - Entry point of the shell program
 * @argc: Argument count
 * @argv: Array of argument values
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *buf = NULL, **array;
	size_t count = 0;

	(void)argc;
	(void)argv;

	while (1)
	{
		array = parse_input(buf, &count);
		execute_command(array);
		free(array);
	}

	free(buf);
	return (0);
}
