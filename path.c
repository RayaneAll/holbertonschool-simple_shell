#include "shell.h"

/**
 * copy_path - Crée une copie du PATH.
 * @path: La chaîne PATH à copier.
 *
 * Return: Copie du PATH, ou NULL en cas d'erreur.
 */
char *copy_path(char *path)
{
	char *path_copy;

	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("strdup");
		return (NULL);
	}

	return (path_copy);
}

/**
 * search_command_in_dir - Cherche une commande dans un répertoire.
 * @dir: Répertoire à rechercher.
 * @command: Commande à rechercher.
 * @full_path: Buffer pour stocker le chemin complet.
 *
 * Return: 1 si la commande est trouvée, 0 sinon.
 */
int search_command_in_dir(char *dir, char *command, char *full_path)
{
	snprintf(full_path, 1024, "%s/%s", dir, command);

	if (access(full_path, X_OK) == 0)
		return (1);

	return (0);
}

/**
 * find_command_in_path - Trouve le chemin complet d'une commande dans PATH.
 * @command: La commande à rechercher.
 *
 * Return: Chemin complet si trouvé, NULL sinon.
 */
char *find_command_in_path(char *command)
{
	char *path = getenv("PATH"), *path_copy, *dir;
	char full_path[1024];

	path_copy = copy_path(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		if (search_command_in_dir(dir, command, full_path))
		{
			free(path_copy);
			return (strdup(full_path));
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
