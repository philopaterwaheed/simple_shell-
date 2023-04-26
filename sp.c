#include "main.h"
void setenv_(void* argument)
{
    char ** arguments = (char**)argument;
    if (arguments[1] != NULL && arguments[2] != NULL)
        {
            int result;
            
            result = set_env_variable(arguments[1], arguments[2], 1);
            if (result == -1) {
                perror("setenv");
            }
        }
}
void unsetenv_(void* argument)
{
    char ** arguments = (char**)argument;
    if(arguments[1] != NULL) {
            int result = unsetenv(arguments[1]);
            if (result == -1) {
                perror("unsetenv");
            }
        }
}
void cd (void* argument)
{       
        char *new_dir;
        char ** arguments = (char**)argument;
            if (arguments[1] == NULL || _strcmp(arguments[1], "~") == 0) {
                new_dir = _getenv("HOME");
            } else if (_strcmp(arguments[1], "-") == 0) {
                new_dir =_getenv("OLDPWD");
            } else {
                new_dir = arguments[1];
            }
           if (chdir(new_dir) != 0) {
                perror("cd");
             }   else {
                 set_env_variable("OLDPWD", getenv("PWD"), 1);
                 set_env_variable("PWD", new_dir, 1);
             }
            

}
void __exit(void* argument)
{
    char ** arguments = (char**)argument;
    if (arguments[1])
        {
            int* num ;
            
            num= ctoi(arguments[1]);
            if (num)
                _exit(*num);
            else
            {
                printf("exit: %s: numeric argument required",arguments[1]);
                free(num);
                exit(2);
            }
        }
    else
    {
        exit(0);
    }
}