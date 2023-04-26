#include "main.h"
/**
* _strncmp - Compares two strings byte-by-byte
* @s1: The first string to compare
* @s2: The second string to compare
* @n: The maximum number of bytes to compare
* Return: 0 if the strings are equal
*/

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
	if (s1[i] != s2[i])
	{
		return ((s1[i] < s2[i]) ? -1 : 1);
	}
	if (s1[i] == '\0')
	{
		break;
	}
	}
	return (0);
}
/**
* _strcmp - Compares two strings byte-by-byte
* @str1: The first string to compare
* @str2: The second string to compare
* Return: 0 if the strings are equal
*/

int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
{
	if (str1[i] != str2[i])
	{
	return ((str1[i] < str2[i]) ? -1 : 1);
	}
	i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return (0);
	}
	return ((str1[i] == '\0') ? -1 : 1);
}
