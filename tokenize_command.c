#include "shell.h"

/**
* tokenize_command - Découpe une commande en arguments.
* @command: Chaîne contenant la commande à découper.
* @argv: Tableau destiné à stocker les arguments.
*
* Cette fonction utilise `strtok` pour diviser une chaîne en plusieurs
* sous-chaînes, en utilisant un espace (`" "`) comme délimiteur.
* Les arguments sont stockés dans un tableau passé par référence.
* Le tableau est terminé par un pointeur NULL.
*/
void tokenize_command(char *command, char **argv)
{
	/* Pointeur pour stocker chaque argument lors de la tokenisation */
	char *token;

	/* Index pour parcourir le tableau argv */
	int i = 0;

	/* Découper la chaîne `command` en tokens avec " " comme délimiteur */
	token = strtok(command, " ");
	while (token != NULL) /* Tant qu'il reste des tokens */
	{
		argv[i++] = token; /* Stocker le token dans le tableau argv */
		token = strtok(NULL, " "); /* Passer au token suivant */
	}

	/* Terminer le tableau argv par NULL, comme attendu par execve */
	argv[i] = NULL;
}
