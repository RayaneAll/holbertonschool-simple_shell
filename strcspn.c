#include "shell.h"

/**
* _strcspn - Calcule la longueur du segment initial d'une chaîne.
*            Ce segment est composé de caractères qui ne se trouvent pas
*            dans une chaîne donnée de caractères rejetés.
* @s: Pointeur vers la chaîne d'entrée.
* @reject: Pointeur vers la chaîne contenant les caractères à rejeter.
*
* Cette fonction parcourt la chaîne `s` jusqu'à ce qu'un caractère
* présent dans `reject` soit rencontré ou que la fin de `s` soit atteinte.
*
* Return: La longueur du segment valide (sans caractères rejetés).
*/
size_t _strcspn(const char *s, const char *reject)
{
	size_t i, j; /* Déclarations des variables pour les boucles */

	/* Parcours de chaque caractère de la chaîne d'entrée `s` */
	for (i = 0; s[i] != '\0'; i++)
	{
		/* Comparaison avec chaque caractère de la chaîne `reject` */
		for (j = 0; reject[j] != '\0'; j++)
		{
			/* Si un caractère de `reject` est trouvé dans `s` */
			if (s[i] == reject[j])
				return (i); /* Retourner la position du premier rejet */
		}
	}

	/* Si aucun caractère `reject` est trouvé, retourner longueur totale `s` */
	return (i);
}
