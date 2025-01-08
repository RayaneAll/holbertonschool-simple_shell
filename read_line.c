#include "shell.h"

/**
* read_line - Lit une ligne d'entrée utilisateur dans un shell.
*
* Cette fonction utilise getline pour lire ligne depuis l'entrée standard.
* Elle gère également la fin de fichier (EOF) en libérant la mémoire
* et en quittant proprement le programme.
*
* Return: Pointeur vers chaîne caractères contenant l'entrée utilisateur.
*         Retourne NULL si une erreur survient.
*/
char *read_line(void)
{
	/* Pointeur pour stocker la ligne d'entrée */
	char *line = NULL;

	/* Taille initiale du tampon allouée par getline */
	size_t size = 0;

	/* Nombre de caractères lus par getline */
	ssize_t nread;

	/* Lecture d'une ligne depuis l'entrée standard */
	nread = getline(&line, &size, stdin);

	/* Vérification de la fin de fichier ou d'une erreur */
	if (nread == -1) /* EOF détecté ou échec de getline */
	{
		/* Libérer la mémoire allouée avant de quitter */
		free(line);
		exit(0); /* Quitter proprement le programme */
	}

	/* Retourner la ligne lue pour une utilisation ultérieure */
	return (line);
}
