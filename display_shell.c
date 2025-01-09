#include "shell.h"

/**
* display_shell - Affiche le prompt du shell.
*
* Cette fonction affiche un prompt personnalisé "#cisfun$ "
* pour inviter l'utilisateur à entrer une commande.
* Elle ne prend aucun argument et ne retourne rien.
*/
void display_shell(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
	}

}
