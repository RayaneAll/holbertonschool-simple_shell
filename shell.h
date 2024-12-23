#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

void display_shell(void);
int execute_command(char *command);
int read_line(void);
int main(void);

#endif /* __SHELL_H__ */
