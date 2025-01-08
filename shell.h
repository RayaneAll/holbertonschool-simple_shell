#ifndef __SHELL_H__
#define __SHELL_H__

/* Inclusion des bibliothèques standard nécessaires */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* Déclaration de la variable globale `environ` */
extern char **environ; /* Utilisée pour accéder variables d'environnement */

/* Prototypes des fonctions utilisées dans le shell */

/**
 * display_shell - Affiche le prompt du shell.
 */
void display_shell(void);

/**
 * execute_command - Exécute une commande entrée par l'utilisateur.
 * @command: Chaîne contenant la commande à exécuter.
 *
 * Return: 0 si l'exécution réussit, 1 en cas d'erreur.
 */
int execute_command(char *command);

/**
 * read_line - Lit une ligne d'entrée utilisateur.
 *
 * Return: Pointeur vers la chaîne contenant l'entrée utilisateur.
 */
char *read_line(void);

/**
 * tokenize_command - Découpe une commande en arguments.
 * @command: Chaîne contenant la commande à découper.
 * @argv: Tableau dans lequel les arguments sont stockés.
 */
void tokenize_command(char *command, char **argv);

/**
 * execute_fork - Crée un processus enfant pour exécuter une commande.
 * @argv: Tableau contenant les arguments de la commande.
 */
void execute_fork(char **argv);

#endif /* __SHELL_H__ */
