#include "main.h"
/**
* _putchar - writes the character c to stdout
* @c: The character to print
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
int i = 0;
if (!str)
return;
while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}
/**
* print_to_stderr - writes a message to stderr
* @message: The message to print
* Return: Nothing
*/
void print_to_stderr(const char *message)
{
write(STDERR_FILENO, message, strlen(message));
}
