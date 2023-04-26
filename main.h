#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdarg.h>
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define MAX_BUFFER_SIZE 1024
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
#define MAX_ENV_VARIABLES 1024
extern char **environ;
int _putchar(char c);
char* _getline();
char** token(char* line);
void exe(char ** arguments);
char *location(char *command);
void env(void* argument);
void spexe(int index, void* arg);
int sp(char * argument);
void echo(void * arguments);
void __exit(void *argument);
char* strfind(char* , char, int);
int* ctoi(char * );
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
int _strcmp(const char* str1, const char* str2);
char *_strncpy(char *dest, char *src, int n);
void str_replace(char *str, const char *substr, const char *new_substr, size_t start, size_t end);
int _strncmp(const char *s1, const char *s2, size_t n);
char * _strappened(char* str, char ch);
void replace_substr(char *str, char *substr, char *replace);
char* _getenv(char* name);
void _eputs(char *);
int array_size(char **array);
void parse (char ** args);
void dollar(char ** args);
void cd (void* argument);
void setenv_(void* argument);
void print_to_stderr(const char *message) ;
void replace_all(char *str, char *substr, char *replace);
void unsetenv_(void* argument);
char *_strchr( char *str, int ch);
int  set_env_variable(char *name, char *value, int overwrite) ;
int _unsetenv(char *name);
/*
       \:.             .:/
        \``._________.''/ 
         \             / 
 .--.--, / .':.   .':. \
/__:  /  | '::' . '::' |
   / /   |`.   ._.   .'|
  / /    |.'         '.|
 /___-_-,|.\  \   /  /.|
      // |''\.;   ;,/ '|
      `==|:=         =:|
         `.          .'
l42        :-._____.-:
          `''       `''
*/