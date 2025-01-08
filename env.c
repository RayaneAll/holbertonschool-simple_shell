#include "shell.h"

/**
* print_env - Affiche les variables d'environnement.
* @envp: Tableau contenant les variables d'environnement.
*/
void print_env(char *envp[])
{
	while (*envp)
	{
		printf("%s\n", *envp);
		envp++;
	}
}
