#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * print_prompt - Prints the shell prompt.
 */
void print_prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * read_input - Reads the user input from the shell.
 * @buffer: Pointer to store the input string.
 * @count: Pointer to the size of the buffer.
 *
 * Return: Number of characters read, or -1 on failure.
 */
ssize_t read_input(char **buffer, size_t *count)
{
	ssize_t nread;

	nread = getline(buffer, count, stdin);
	if (nread == -1)
	{
		perror("Exiting shell");
		free(*buffer);
		exit(1);
	}
	return (nread);
}

/**
 * tokenize_input - Tokenizes the user input into an array of strings.
 * @buffer: Input string from the user.
 *
 * Return: Array of strings (tokens), or NULL on failure.
 */
char **tokenize_input(char *buffer)
{
	char **array;
	char *token;
	int i;

	array = malloc(sizeof(char *) * 1024);
	if (array == NULL)
	{
		perror("Allocation failed");
		free(buffer);
		exit(2);
	}

	token = strtok(buffer, " \n");
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
 * execute_command - Forks and executes a command in a child process.
 * @array: Array of strings representing the command and its arguments.
 * @buffer: Buffer containing the original input (for cleanup).
 */
void execute_command(char **array, char *buffer)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Failed to create process");
		free(array);
		free(buffer);
		exit(41);
	}

	if (child_pid == 0)
	{
		if (execve(array[0], array, NULL) == -1)
		{
			perror("Couldn't execute");
			free(array);
			free(buffer);
			exit(97);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * main - Entry point for our simple shell program.
 *
 * Return: 0 Always success.
 */
int main(void)
{
	char *buffer = NULL;
	size_t count = 0;
	char **array;

	while (1)
	{
		print_prompt();
		read_input(&buffer, &count);
		array = tokenize_input(buffer);
		execute_command(array, buffer);
		free(array);
	}

	free(buffer);
	return (0);
}
