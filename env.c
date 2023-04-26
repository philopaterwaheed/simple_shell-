#include "main.h"
void env(void* argument)
{
    char ** env = environ ; 
    (void) argument;
    while(*env)
    {
        _eputs(*env);
        _eputs("\n");
        env ++; 
    }
}
char* _getenv(char* name)
{
    int i;    
    for (i = 0; environ[i] != NULL; i++) {
        char* var = environ[i];
        int j;
        
        for (j = 0; name[j] != '\0' && var[j] == name[j]; j++);
        
        if (name[j] == '\0' && var[j] == '=') {
            char* value = &var[j+1];
            return value;
        }
    }    
    return NULL;
}
int  set_env_variable(char *name,  char *value, int overwrite) {
    int result;
    char *var ;
    if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL) {
        print_to_stderr( "setenv: invalid argument '%s'\n");
        return -1;
    }

    if (!overwrite && getenv(name) != NULL) {
        return 0;
    }

    var = malloc(_strlen(name) + _strlen(value) + 2);
    if (var == NULL) {
        return -1;
    }

    sprintf(var, "%s=%s", name, value);
    result = putenv(var); 

    if (result != 0) {
        free(var);
    }

    return result;
}
int _unsetenv( char *name) {
    char **env, **new_env;
    int count = 0;
    int i, j;

    if (name[0] == '\0' || name[0] == '\0' || _strchr(name, '=') != NULL) {
        print_to_stderr( "unsetenv: invalid argument \n");
        return -1;
    }
    for (env = environ; *env != NULL; env++) {
        count++;
    }

    new_env = malloc(count * sizeof(char *));
    if (new_env == NULL) {
        print_to_stderr( "unsetenv: out of memory\n");
        return -1;
    }
    for (i = 0, j = 0; environ[i] != NULL; i++) {
        if (_strncmp(environ[i], name, _strlen(name)) != 0 || environ[i][_strlen(name)] != '=') {
            new_env[j++] = environ[i];
        }
    }
    new_env[j] = NULL;
    environ = new_env;
    return 0;
}