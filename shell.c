#include "shell.h"

/**
* main - Point d'entrée du programme shell.
*
* Cette fonction initialise une boucle infinie pour exécuter le shell.
* À chaque itération, elle affiche le prompt, lit une commande,
* et exécute cette commande. Elle gère également la mémoire pour
* chaque commande entrée par l'utilisateur.
*
* Return: Toujours 0 (succès).
*/
int main(void)
{
	/* Pointeur pour stocker la commande entrée par l'utilisateur */
	char *command;

	/* Boucle infinie pour le fonctionnement continu du shell */
	while (1)
	{
		/* Afficher le prompt du shell à l'utilisateur */
		display_shell();

		/* Lire une ligne d'entrée utilisateur */
		command = read_line();

		/* Vérifier si aucune commande n'a été entrée */
		if (command == NULL)
			continue; /* Ignorer et passer à la prochaine itération */

		/* Exécuter la commande entrée par l'utilisateur */
		execute_command(command);

		/* Libérer la mémoire allouée pour la commande */
		free(command);
	}

	/* Retourner 0 pour indiquer un succès (jamais atteint ici) */
	return (0);
}
