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

		while (1)
		{
			printf("#cisfun$ ");
			nread = getline(&buffer, &count, stdin);

			if (nread == -1)
			{
				perror("Exiting shell");
				exit(1);
			}
			printf("%s", buffer);
		}
		free(buffer);
		return (0);
}
