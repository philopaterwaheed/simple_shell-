#include "main.h"

/**
 * location - searches for the location of a given command in the PATH
 * @command: command to search for
 *
 * Return: a pointer to a string with the location of the command, or NULL
 * if the command was not found.
 */

char *location(char *command)
{
char *path, *path_c, *path_t, *file;
int len, dlen;
struct stat buffer;
path = getenv("PATH");
path_c = strdup(path);
len = strlen(command);
path_t = strtok(path_c, ":");
while (path_t)
{
dlen = strlen(path_t);
file = malloc(len + dlen + 2);
strcpy(file, path_t);
strcat(file, "/");
strcat(file, command);
strcat(file, "\0");
if (stat(file, &buffer) == 0)
{
free(path_c);
return (file);
}
else
{
free(file);
path_t = strtok(NULL, ":");
}
}
free(path_c);
if (stat(command, &buffer) == 0)
{
return (command);
}
return (NULL);
}
