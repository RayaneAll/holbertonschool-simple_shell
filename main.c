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

		char **array;

		char *token;

		int i;

		while (1)
		{
			printf("#cisfun$ ");
			nread = getline(&buffer, &count, stdin);

			if (nread == -1)
			{
				perror("Exiting shell");
				exit(1);
			}

			token = strtok(buffer, " \n");
            array = malloc(sizeof(char *) * 1024);
            i = 0;
            while (token)
            {
                array[i] = token;
                token = strtok(NULL, " \n");
                i++;
            }
            array[i] = NULL;

			child_pid = fork();

			if (child_pid == -1)
			{
				perror("Failed to create.");
				exit(41);
			}

			if (child_pid == 0)
			{
				if (execve(array[0], array, NULL) == -1)
				{
					perror("Couldn't execute");
					exit(97);
				}
			}
			else
			{
				wait(&status);
			}
		}
		free(buffer);
		return (0);
}
