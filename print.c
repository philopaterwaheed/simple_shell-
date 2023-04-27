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
/**
 * _sprintf - Formats and prints a string to a buffer
 *
 * @buffer: The buffer to write the formatted string to
 * @format: The format string
 * @...: Additional arguments to format
 *
 * Return: The number of characters written, or a negative value on error
 */
int _sprintf(char *buffer, const char *format, ...)
{
    va_list args;
    int count;

    va_start(args, format);
    count = vsprintf(buffer, format, args);
    va_end(args);

    if (count < 0)
    {
        /* Error occurred */
        return -1;
    }

    return (count);
}