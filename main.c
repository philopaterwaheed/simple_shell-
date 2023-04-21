#include "main.h"

int main(void)
{
    while (1)
    {
        
        char *line = "exit";
        char **arguments;


        
        /* prints the sell sign */
        line = _getline();
        if (line)
        {
            arguments = token(line);
            exe (arguments);
            free(line);
            free(arguments);
        }   
        else 
            break;
    }
    return (0);
}
