#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

void display_shell(void);
int execute_command(char *command);

char *read_line(void);
size_t _strlen(const char *s);

size_t _strcspn(const char *s, const char *reject);

#endif /* __SHELL_H__ */
