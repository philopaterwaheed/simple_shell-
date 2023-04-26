#include "main.h"
/**
* _strncpy - does some thing
* @dest: detneation
* @src:	sourc
* @n: n
* Return: @dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	char *r = dest;
	int i;

	for (i = 0; i < n && *src; src++, dest++, i++)
		*dest = *src;
	for (; i < n; i++, dest++)
	*dest = 0;
	*dest = '\0';
	return (r);
}
/**
 * _strcpy - copies the string
 * @dest: the reference to copy
 * @src: the reference to copy from
 * Return: the reference
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	char c;

	i = 0;
	while (1)
	{
		c = *(src + i);
		*(dest + i++) = c;
		if (c == '\0')
			break;
	}
	return (dest);
}
/**
* _memcpy - does some thing
* @dest: detneation
* @src:	sourc
* @n: n
* Return: @dest
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(dest + i) = *(src + i);

	return (dest);
}
