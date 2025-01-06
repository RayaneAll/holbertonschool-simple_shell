#ifndef __SHELL_H__
#define __SHELL_H__

/* Inclusion des bibliothèques standard nécessaires */
#include <stdio.h>   /* Pour les fonctions d'entrée/sortie comme printf */
#include <unistd.h>  /* Pour les appels système comme fork, execve, etc. */
#include <stdlib.h>  /* Pour la gestion de mémoire dynamique et exit */
#include <string.h>  /* Pour les fonctions de manipulation de chaînes */

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
 * _strlen - Calcule la longueur d'une chaîne de caractères.
 * @s: Chaîne dont la longueur doit être calculée.
 *
 * Return: Longueur de la chaîne.
 */
size_t _strlen(const char *s);

/**
 * _strcspn - Calcule la longueur de la partie initiale d'une chaîne
 *            qui ne contient aucun des caractères de la chaîne `reject`.
 * @s: Chaîne d'entrée.
 * @reject: Chaîne contenant les caractères à éviter.
 *
 * Return: Longueur de la partie valide de `s`.
 */
size_t _strcspn(const char *s, const char *reject);

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
