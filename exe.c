#include "main.h"
/**
 * echo - prints the input arguments to standard output
 * @arguments: the arguments passed to the echo command
 *
 * Return: Nothing
 */
void echo(void *arguments)
{
(void) arguments;
}
/**
 * exe - executes a given command
 * @arguments: an array of strings representing the command and its arguments
 *
 * Return: Nothing
 */
void exe(char **arguments)
{
pid_t pid;
char *command = NULL, *excommand;
int status;
if (sp(arguments[0]) != -1)
{
spexe(sp(arguments[0]), arguments);
return;
}
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
perror(arguments[0]);
};
}
}
else
{
waitpid (pid, &status, 0);
}
}
/**
 * sp - identifies the index of a command in an array of commands
 * @argument: the command to be searched
 *
 * Return: the index of the command if found, -1 otherwise
 */
int sp(char *argument)
{
int i;
char *sp [] = {"env", "exit", "cd", "setenv", "unsetenv"};
for (i = 0; i < 5; i++)
if (_strcmp(argument, sp[i]) == 0)
return (i);
return (-1);
}
/**
 * spexe - executes a special command
 * @index: the index of the command to be executed
 * @arg: the arguments to be passed to the command
 *
 * Return: Nothing
 */
void spexe(int index, void *arg)
{
void (*fun[]) (void *) = {env, __exit, cd, setenv_, unsetenv_};
(*fun[index])(arg);
}
