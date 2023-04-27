#include "main.h"
/**
 * token - Split a string into an array of tokens
 * @line: The string to tokenize
 *
 * Return: A pointer to an array of pointers to strings,each containing token
 * from the input string, or NULL if memory allocation fails.
 */
char **token(char *line)
{
char **arguments;
char *line_copy, *token;
size_t words = 0;
int i;
line_copy = malloc(sizeof(char) * (_strlen(line) + 1));
if (!line_copy)
/*on memory falling */
{
_eputs("Failed to allocate");
return (NULL);
}
_strcpy(line_copy, line);
/*make a copy of the line to edit it*/
token = strtok(line_copy, " \n");
words++;
while (token)
{
token = strtok(NULL, " \n");
words++;
}
free(line_copy);
arguments = malloc(words *sizeof(char *));
if (!arguments)
{
_eputs("Failed to allocate");
return (NULL);
}
token = strtok(line, " \n");
for (i = 0 ; token != NULL ; i++)
{
arguments[i] = malloc(sizeof(char) * (_strlen(token) + 1));
/* allocate memmory into of the i'th element */
if (!arguments[i])
{
_eputs("Failed to allocate");
while (i--)
free(arguments[i]);
free(arguments);
return (NULL);
}
_strcpy(arguments[i], token);
/*puts the token inside the array*/
token = strtok(NULL, " \n");
}
return (arguments);
}
