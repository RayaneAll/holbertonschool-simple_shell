# <span style="color:orange;"> THE SIMPLE SHELL</span>
A simple shell is a basic software program that provides a text-based interface between the user and the operating system, allowing users to interact with the computer by typing commands directly.

- [ THE SIMPLE SHELL](#-the-simple-shell)
- [ Function](#-function)
  - [Functions and Definitions](#functions-and-definitions)
  - [Compilation command](#compilation-command)
  - [Requirements](#requirements)
  - [Usage Examples](#usage-examples)
- [Man Page - Command to exectue Man page:](#man-page---command-to-exectue-man-page)
- [Testing ](#testing-)
- [Flowchart](#flowchart)
- [Authors](#authors)
# <span style="color:yellow;"> Function</span>
## Functions and Definitions
  - <span style="color:brown;"> Display_shell:</span> *Displays a prompt for the user to enter a command. It typically represents the interactive shell.*
 - <span style="color:brown;"> Execute_command:</span> *Executes a command by searching for its path in PATH, then launches a child process using execve. It also handles special commands like exit and env.*
- <span style="color:brown;"> Read_line:</span> *Reads a line of input entered by the user, usually using fgets or getline to capture standard input.*
- <span style="color:brown;"> Tokenize_command:</span> *Splits a command line into tokens (arguments) separated by spaces or special characters, typically using strtok, to prepare for execution.*
 - <span style="color:brown;"> Execute_fork:</span> *Creates a child process using fork to execute a command. The child process uses execve to run the command, while the parent process waits for the child to finish.*
- <span style="color:brown;"> Main:</span> *The main function of the program, typically responsible for initialization, displaying the prompt, managing the command input loop, and executing commands until exit.*
## <span style="color:green;">Compilation command</span>
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
## <span style="color:pink;">Requirements</span>
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, 
Using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (why?)

## <span style="color:cyan;">Usage Examples</span>
**PID (Process Identifier) and PPID (Parent Process Identifier)**
Are fundamental concepts in operating systems for managing processes.
1. <span style="color:red;">PID</span> (Process Identifier): _A PID is a unique number given to each running program on a
computer. It helps the system track and manage different processes, like giving each running program its own “name tag”_
2. <span style="color:red;">PIDD</span> (Parent Process Identifier): _A PPID is the number (ID) of the parent process that started another process. It shows which process created it. For example, if a program starts another program, the first one is the “parent”, and its ID the PPID of the second one._
PID
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
pid_t pid = fork(); // Create a new process
if (pid < 0)
{
// Error occurred during fork
perror("Error during fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
// Code executed by the child process
printf("I am the child process. My PID is %ld and my parent's PID is %ld.\n", (long)getpid(),
(long)getppid());
} else
 {
// Code executed by the parent process
printf("I am the parent process. My PID is %ld and my child's PID is %ld.\n", (long)getpid(),
(long)pid);
}
return( EXIT_SUCCESS);
}
# <span style="color:magenta;">Man Page - Command to exectue Man page:</span>
Access to the main page with man_1_simple_shell
# <span style="color:yellowgreen;">Testing </span>
![alt text](<IMG_7844.png>)
# <span style="color:purple;">Flowchart</span>
![alt text](<E4208301-2737-4C12-87EE-CFCDF6CB9866_1_105_c.jpeg>)
# <span style="color:aqua;">Authors</span>

- **ALLAOUI RAYANE** - [RayaneAll](https://github.com/RayaneAll)
- **MOUROUX MATTIEU** - [Mattieuuu](https://github.com/Mattieuuu)