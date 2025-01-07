#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/* Variables globales */
extern char **environ;

/* Fonctions principales */
void display_shell(void);
int execute_command(char *command);
char *read_line(void);

/* Fonctions liées à l'environnement */
void print_env(void);

/* Fonctions liées au PATH */
char *find_command_in_path(char *command);
char *copy_path(char *path);
int search_command_in_dir(char *dir, char *command, char *full_path);

/* Fonctions liées aux commandes */
int parse_command(char *command, char *argv[]);
int handle_builtin_commands(char *argv[], char *command);

#endif /* __SHELL_H__ */
