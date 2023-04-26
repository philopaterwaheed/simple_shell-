#include "main.h"
void echo(void * arguments)
{
    (void) arguments;
}

void exe(char ** arguments)
{
    pid_t pid;
    char* command = NULL , *excommand;
    int status;
    
    if (sp(arguments[0]) != -1){
        spexe(sp(arguments[0]), arguments);
        return;
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
    }
    else if (pid ==0 ) {
        if (arguments)
        {
            command = arguments[0] ;         
            excommand = location(command);
            if (execve(excommand, arguments, NULL) == -1)
            {
                perror(arguments[0]);
            };
        }
    }
     else {
        waitpid (pid, &status, 0); 
     }
}
int sp(char * argument)
{
    int i;
    char*  sp [] = {"env" ,"exit","cd","setenv","unsetenv" };
    for (i = 0; i < 5;i++)
        if(_strcmp(argument,sp[i]) == 0)
            return i;
    return -1;

}
void spexe(int index, void* arg)
{
    void (*fun[]) (void*) = {env,__exit,cd,setenv_,unsetenv_};
    (*fun[index])(arg);
/*
    ╔╗    ╔╗                                         
    ║║    ║║                                         
╔══╗║╚═╗╔╗║║ ╔══╗    ╔╗╔══╗    ╔══╗╔╗╔═╗ ╔╗╔╗╔══╗╔══╗
║╔╗║║╔╗║╠╣║║ ║╔╗║    ╠╣║══╣    ║╔╗║╠╣║╔╗╗║║║║║╔╗║║══╣
║╚╝║║║║║║║║╚╗║╚╝║    ║║╠══║    ║╚╝║║║║║║║║╚╝║║║═╣╠══║
║╔═╝╚╝╚╝╚╝╚═╝╚══╝    ╚╝╚══╝    ╚═╗║╚╝╚╝╚╝╚══╝╚══╝╚══╝
║║                             ╔═╝║                  
╚╝                             ╚══╝                  
*/
}