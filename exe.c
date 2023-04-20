#include "main.h"

/**
 * exe - executes a command with arguments
 * @arguments: an array of strings containing the command and its arguments
 */

void env(void)
{
extern char **environ;
char **env = environ;
while (*env)
{
printf("%s\n", *env);
env++;
}
}
void exe(char **arguments)
{
pid_t pid;
char *command = NULL, *excommand;
int status;
if (strcmp(arguments[0], "env") == 0)
env();
pid = fork();
if (pid == -1)
{
perror("fork");
}
else if (pid == 0)
{
if (arguments)
{
command = arguments[0];
excommand = location(command);
if (execve(excommand, arguments, NULL) == -1)
{
perror("Error:");
};
}
}
else
{
waitpid (pid, &status, 0);
}
}
