#include "main.h"
/**
* replace_substr - does some thing
* @str: detneation
* @substr: sourc
* @replace: n
* Return: @dest
*/

void replace_substr(char *str, char *substr, char *replace)
{
	int substr_len = _strlen(substr);
	int replace_len = _strlen(replace);
	int str_len = _strlen(str);
	int i = 0;

	while (i <= str_len - substr_len)
{
		if (_strncmp(str + i, substr, substr_len) == 0)
{
			_memmove(str + i + replace_len, str + i
+ substr_len, str_len - i - substr_len + 1);
			_memcpy(str + i, replace, replace_len);
			str_len += replace_len - substr_len;
			i += replace_len;
		}
		else
{
			i++;
}
	}
}
/**
* replace_all - does some thing
* @str: detneation
* @substr: sourc
* @replace: n
* Return: @dest
*/

void replace_all(char *str, char *substr, char *replace)
{
	int substr_len = strlen(substr);
	int replace_len = strlen(replace);
	int str_len = strlen(str);
	char *pos = strstr(str, substr);

	while (pos != NULL)
{
		_memmove(pos + replace_len, pos + substr_len, str
+ str_len - pos - substr_len + 1);
		_memcpy(pos, replace, replace_len);
		str_len += replace_len - substr_len;
		pos = strstr(pos + replace_len, substr);
	}
}
void str_replace(char *str, const char *substr,
const char *new_substr, size_t start, size_t end)
{
	size_t substr_len = strlen(substr);
	size_t new_substr_len = strlen(new_substr);
	size_t len = strlen(str);
	size_t i, j;

	if (end > len)
{
		end = len;
	}
	if (start > end)
{
		start = end;
	}
	if (start + substr_len > len)
{
		return;
	}
	if (new_substr_len > substr_len)
{
		size_t diff = new_substr_len - substr_len;

		for (i = end; i <= len; i++)
{
			str[i + diff] = str[i];
		}
	}
	else if (new_substr_len < substr_len)
{
		size_t diff = substr_len - new_substr_len;

		for (i = end; i <= len; i++)
{
			str[i - diff] = str[i];
		}
	}
	for (i = start, j = 0; i < (start + new_substr_len); i++, j++)
	{
		str[i] = new_substr[j];
	}
}
