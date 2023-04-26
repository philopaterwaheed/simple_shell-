#include "main.h"
/**
 * location - Returns the full path of a command or file
 *
 * @command: String representing the command or file name
 *
 * Return: Pointer to string containing full path if found, otherwise NULL
 */
char *location(char *command)
{
char *path, *path_c, *path_t, *file;
int len, dlen;
struct stat buffer;
path = _getenv("PATH");
path_c = _strdup(path);
len = _strlen(command);
path_t = strtok(path_c, ":");
while (path_t)
{
dlen = _strlen(path_t);
file = malloc(len + dlen + 2);
_strcpy(file, path_t);
_strcat(file, "/");
_strcat(file, command);
_strcat(file, "\0");
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
