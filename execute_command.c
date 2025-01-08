#include "shell.h"

/**
* execute_command - Exécute une commande en utilisant execve.
* @command: La commande à exécuter, sous forme de chaîne de caractères.
*
* Cette fonction analyse la commande, vérifie son accessibilité
* et utilise fork pour créer un processus enfant qui l'exécute.
*
* Return: 0 succès, 1 si commande invalide ou ne peut pas être exécutée.
*/
int execute_command(char *command)
{
	/* Tableau pour stocker les arguments de la commande après tokenisation */
	char *argv[100];

	/* Supprimer le caractère de nouvelle ligne à la fin de la commande */
	command[strcspn(command, "\n")] = '\0';

	/* Vérifier si la commande est vide ou nulle */
	if (command == NULL || strlen(command) == 0)
		return (1); /* Retourne une erreur si aucune commande valide n'est fournie */

	/* Découper la commande en arguments avec tokenize_command */
	tokenize_command(command, argv);

	/* Vérifier si le fichier est accessible et exécutable */
	if (access(argv[0], X_OK) == -1)
	{
		/* Afficher un message d'erreur si le fichier est inaccessible */
		perror("./shell");
		return (1); /* Retourne erreur si la commande ne peut pas être exécutée */
	}

	/* Appeler execute_fork pour forker et exécuter la commande */
	execute_fork(argv);

	/* Retourne 0 pour indiquer que l'exécution a réussi */
	return (0);
}
