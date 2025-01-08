#include "shell.h"

/**
* execute_fork - Crée un processus enfant pour exécuter une commande.
* @argv: Tableau chaînes caractères contenant les arguments de la commande.
*
* Cette fonction utilise fork pour créer un processus enfant.
* Dans le processus enfant, execve est utilisé pour exécuter la commande.
* Le processus parent attend la fin de l'exécution de l'enfant.
*/
void execute_fork(char **argv)
{
	/* Déclaration de variable pour stocker le PID et le statut du processus */
	pid_t pid;
	int status;

	/* Création d'un nouveau processus via fork */
	pid = fork();
	if (pid == 0) /* Si le processus enfant est créé avec succès */
	{
		/* Exécution de la commande via execve */
		if (execve(argv[0], argv, environ) == -1)
		{
			/* Afficher une erreur si execve échoue */
			perror("./shell");
			/* Quitter immédiatement le processus enfant en cas d'échec */
			_exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0) /* Si on est dans le processus parent */
	{
		/* Attendre la fin du processus enfant et récupérer son statut */
		wait(&status);
	}
	else /* Si fork échoue */
	{
		/* Afficher un message d'erreur si la création du processus échoue */
		perror("fork");
	}
}
