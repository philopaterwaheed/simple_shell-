#include "main.h"
/**
 * main - Entry point for the shell program
 *
 * Return: Always 0
 */
int main(void)
{
while (1)
{
char *line = "exit";
char **arguments;
line = _getline();
if (line != NULL)
{
arguments = token(line);
parse(arguments);
exe(arguments);
free(line);
free(arguments);
}
else
continue;
}
return (0);
}
