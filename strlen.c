#include "shell.h"

/**
* _strlen - Calcule la longueur d'une chaîne de caractères.
* @s: Pointeur vers la chaîne dont on veut calculer la longueur.
*
* Cette fonction parcourt chaque caractère de la chaîne jusqu'à
* rencontrer le caractère nul `\0`, indiquant la fin de la chaîne.
*
* Return: Longueur de la chaîne (nombre de caractères avant le `\0`).
*/
size_t _strlen(const char *s)
{
	/* Variable pour stocker la longueur de la chaîne */
	size_t len = 0;

	/* Parcours de la chaîne jusqu'à la fin (caractère nul) */
	while (s[len] != '\0')
	{
		len++; /* Incrémenter la longueur pour chaque caractère */
	}

	/* Retourner la longueur totale de la chaîne */
	return (len);
}
