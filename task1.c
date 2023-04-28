#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define PROMPT "> "

/**
 * main - Entry point of the simple shell program.
 *
 * This function repeatedly prompts
 * the user for a single-word command
 * and executes it by creating a child
 * process with fork() and replacing
 * it with the specified command using execvp().
 * The function also handles
 * errors, including a command not found error
 * and a terminated by signal error.
 * The program exits gracefully when the end-of-file
 * condition (CTRL+D) is encountered.
 *
 * Return: 0 on successful completion.
 */
int main(void)
{
char command[MAX_COMMAND_LENGTH];
while (printf("%s", PROMPT), fgets(command, MAX_COMMAND_LENGTH, stdin))
{
/* Remove trailing newline character */
command[strcspn(command, "\n")] = '\0';
pid_t pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
execlp(command, command, (char *) NULL);
perror("execlp");
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
{
/* Executable not found */
fprintf(stderr, "Error: command not found: %s\n", command);
}
else if (WIFSIGNALED(status))
{
/* Terminated by signal */
fprintf(stderr, "Error: process terminated by signal %d\n", WTERMSIG(status));
}
}
}
return (0);
}

