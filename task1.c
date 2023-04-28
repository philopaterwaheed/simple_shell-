#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0 on success.
 */
int main(void)
{
char *buffer = NULL;
size_t bufsize = 0;
ssize_t nread;
char *args[2];
int status;

while (1)
{
printf("$ ");
nread = getline(&buffer, &bufsize, stdin);
/* Handle end of file condition */
if (nread == -1)
{
if (feof(stdin))
{
printf("\n");
exit(EXIT_SUCCESS);
}
else
{
perror("getline");
exit(EXIT_FAILURE);
}
}
/* Remove trailing newline character */
if (buffer[nread - 1] == '\n')
{
buffer[nread - 1] = '\0';
}
/* Parse good  command */
args[0] = buffer;
args[1] = NULL;
/* Execute hihi command */
if (execve(args[0], args, NULL) == -1)
{
printf("Error: %s\n", strerror(errno));
}
}
free(buffer);
exit(status);
}

