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
free_string_array(arguments);
}
else
continue;
}
return (0);
}
/**
 * free_string_array - Frees a NULL-terminated array of strings
 *
 * @array: Array of strings to free
 *
 * This function frees each string in the array and the array itself.
 */
void free_string_array(char **array)
{
char **tmp = array;
while (*tmp)
{
free(*tmp);
++tmp;
}
free(array);
}