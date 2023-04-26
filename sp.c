#include "main.h"
/**
* setenv_ - Sets a new environment variable or updates an existing one
*
* @argument: Array of arguments passed to the function
*
* This function takes an array of arguments that includes
* the name and value of the environment variable
* to set, and sets or updates the environment variable accordingly.
* If the environment variable is successfully set or updated,
* it returns 0. If an error occurs,
* it prints an error message to stderr
* and returns -1.
*/
void setenv_(void *argument)
{
char **arguments = (char **)argument;
if (arguments[1] != NULL && arguments[2] != NULL)
{
int result;
result = set_env_variable(arguments[1], arguments[2], 1);
if (result == -1)
{
perror("setenv");
}
}
}
/**
* unsetenv_ - Unsets an existing environment variable
*
* @argument: Array of arguments passed to the function
*
* This function takes an array of arguments that includes
* the name of the environment variable
* to unset, and unsets the environment variable accordingly.
* If the environment variable is
* successfully unset, it returns 0. If an error occurs,
* it prints an error message to stderr
* and returns -1.
*/
void unsetenv_(void *argument)
{
char **arguments = (char **)argument;
if (arguments[1] != NULL)
{
int result = unsetenv(arguments[1]);
if (result == -1)
{
perror("unsetenv");
}
}
}
/**
* cd - Changes the current working directory
*
* @argument: Array of arguments passed to the function
*
* This function takes an array of arguments that includes
* the path of the directory to change to.
* If the path is NULL or "~", it changes to the user's home directory.
* If the path is "-", it changes to the previous working directory.
* If the path is a valid directory, it changes to that directory.
* If an error occurs, it prints an error message to stderr.
*/
void cd(void *argument)
{
char *new_dir;
char **arguments = (char **)argument;
if (arguments[1] == NULL || _strcmp(arguments[1], "~") == 0)
{
new_dir = _getenv("HOME");
}
else if (_strcmp(arguments[1], "-") == 0)
{
new_dir = _getenv("OLDPWD");
}
else
{
new_dir = arguments[1];
}
if (chdir(new_dir) != 0)
{
perror("cd");
}
else
{
set_env_variable("OLDPWD", getenv("PWD"), 1);
set_env_variable("PWD", new_dir, 1);
}
}
/**
* __exit - Exits the shell
*
* @argument: Array of arguments passed to the function
*
* This function takes an array of arguments that includes
* the exit status to exit with.
* If the exit status is not provided, it exits with status 0.
* If the exit status is not a valid integer,
* it prints an error message to stderr and exits with status 2.
* Otherwise, it exits with the provided exit status.
*/
void __exit(void *argument)
{
char **arguments = (char **)argument;
if (arguments[1] && !arguments[2])
{
int *num;
num = ctoi(arguments[1]);
if (num)
_exit(*num);
else if (array_size(arguments) > 2)
{
	_eputs("too many arguments");
	exit(2);
}
else
{
_eputs("exit: ");
_eputs(arguments[1]);
_eputs(": numeric argument required");
free(num);
exit(2);
}
}
else
{
exit(0);
}
}
