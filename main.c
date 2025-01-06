#include "main.h"

/**
* main - Main entry point for our program
*
* Return: O Always success
*/

int main(void)
{
		char *buffer = NULL;

		size_t count = 0;
		ssize_t nread;
		pid_t child_pid;
		int status;

		while (1)
		{
			printf("#cisfun$ ");
			nread = getline(&buffer, &count, stdin);

			if (nread == -1)
			{
				perror("Exiting shell");
				exit(1);
			}

			child_pid = fork();

			if (child_pid == -1)
			{
				perror("Failed to create.");
				exit(41);
			}

			if (child_pid == 0)
			{
				printf("The creation was successful\n");
			}
			else
			{
				wait(&status);
			}
		}
		free(buffer);
		return (0);
}
