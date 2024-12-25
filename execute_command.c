#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * execute_command - Executes a command using execve
 * @command: The command to execute
 *
 * Return: 0 on success, 1 if command is invalid or cannot be executed.
 */
int execute_command(char *command)
{
    char *argv[100]; /* Array to hold command and arguments */
    char *token;
    pid_t pid;
    int status;
    int i = 0;

    /* Trim newline from command */
    command[_strcspn(command, "\n")] = '\0';

    if (command == NULL || _strlen(command) == 0)
        return (1);

    /* Tokenize the command to split it into arguments */
    token = strtok(command, " ");
    while (token != NULL)
    {
        argv[i++] = token;
        token = strtok(NULL, " ");
    }
    argv[i] = NULL; /* Null-terminate the arguments array */

    /* Check if the command is accessible */
    if (access(argv[0], X_OK) == -1)
    {
        perror("./shell");
        return (1);
    }

    /* Fork a child process to execute the command */
    pid = fork();
    if (pid == 0) /* Child process */
    {
        if (execve(argv[0], argv, environ) == -1)
        {
            perror("./shell");
            _exit(EXIT_FAILURE);
        }
    }
    else if (pid > 0) /* Parent process */
    {
        wait(&status);
    }
    else /* Fork failed */
    {
        perror("fork");
    }

    return (0);
}
