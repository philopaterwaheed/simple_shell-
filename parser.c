#include "main.h"
/**
 * dollar - replaces environment variables with their value
 * @arg: pointer to array of strings containing command and its arguments
 *
 * Return: void
 */
void dollar(char **arg)
{
int c;
for (c = 0; c < array_size(arg); c++)
{
char *dollar = strfind(arg[c], '$', 0);
char *tempo;
tempo = malloc(_strlen(_getenv("PATH")) * sizeof(char));
tempo = _getenv("PATH");
replace_all(arg[c], "$PATH", tempo);
while (dollar != NULL)
{
int i;
char *var;
char *temp;
var = malloc(sizeof(char) * _strlen(dollar - 1));
for (i = 0; (i < _strlen(dollar)) && !(dollar[i] == '$' && i != 0); i++)
_strncpy(var, dollar, i);
if (_getenv(&var[1]))
{
temp = malloc(_strlen(_getenv(&var[1])) * sizeof(char));
temp = _getenv(&var[1]);
replace_all(arg[c], var, temp);
}
else
{
replace_all(arg[c], var, "");
}
dollar = strfind(arg[c], '$', dollar - arg[c] + i);
}
}
}
/**
 * parse - calls necessary functions to parse and execute a command
 * @args: pointer to array of strings containing command and its arguments
 *
 * Return: void
 */
void parse(char **args)
{
dollar(args);
}
