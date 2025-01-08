#include "shell.h"

/**
* parse_command - Découpe une commande en arguments.
* @command: Ligne de commande à découper.
* @argv: Tableau pour stocker les arguments.
*
* Return: Nombre d'arguments.
*/
int parse_command(char *command, char *argv[])
{
	char *token;

	int i = 0;

	token = strtok(command, " \n");
	while (token != NULL && i < 1023)
	{
		argv[i++] = token;
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;

	return (i);
}

/**
* handle_builtin_commands - Gère les commandes intégrées ("env", "exit").
* @argv: Tableau des arguments.
* @command: Ligne de commande.
* @envp: Tableau contenant les variables d'environnement.
*
* Return: 1 si une commande intégrée a été exécutée, 0 sinon.
*/
int handle_builtin_commands(char *argv[], char *command, char *envp[])
{
	if (argv[0] && strcmp(argv[0], "env") == 0)
	{
		print_env(envp);
		return (1);
	}

	if (argv[0] && strcmp(argv[0], "exit") == 0)
	{
		free(command);
		printf("Vous avez tapé EXIT, vous allez quitter le programme\n");
		exit(0);
	}

	return (0);
}

/**
* execute_command - Exécute une commande avec gestion du PATH.
* @command: La ligne de commande à exécuter.
* @envp: Tableau contenant les variables d'environnement.
*
* Return: 0 en cas de succès, 1 si la commande est invalide.
*/
int execute_command(char *command, char *envp[])
{
	char *argv[1024];

	char *path = NULL;

	pid_t pid;
	int status;

	if (parse_command(command, argv) == 0)
		return (1);

	if (handle_builtin_commands(argv, command, envp))
		return (0);

	path = find_command_in_path(argv[0]);
	if (!path)
	{
		fprintf(stderr, "%s: Command not found\n", argv[0]);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, argv, envp) == -1)
		{
			perror(argv[0]);
			_exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
		wait(&status);
	else
		perror("fork");

	free(path);
	return (0);
}
