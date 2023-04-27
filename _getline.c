#include "main.h"
/**
* _getline - Reads an entire line from a file descriptor
* Return: A pointer to the read line, or NULL on failure or end of file
*/
char *_getline()
{
char *line = " ";
int line_read, piped = 0;
size_t size = 0;
/* to store the size of the line */
if (isatty(STDIN_FILENO))
{
_eputs("($) ");
fflush(stdout);
line_read = getline(&line, &size, stdin);
if (line_read == 1)
return (NULL);
}
else
{
line_read = getline(&line, &size, stdin);
if (line_read == -1)
{
free(line);
return (NULL);
}
}
if (line_read == -1 && !piped)
{
_eputs("Exiting shell....\n");
/*makes working  = -1 so that shell exits*/
free(line);
return (NULL);
}
return (line);
}
