#include "main.h"
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
 
void print_to_stderr(const char *message) {
    write(STDERR_FILENO, message, strlen(message));
}
