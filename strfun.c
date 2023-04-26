#include "main.h"


char* strfind(char* str, char ch, int index)
{
char* start = str + index;
while (*str && *str != ch) {
    str++; 
}

if (*str) {
    char* result;
    char* end ;
    str++; 
    end = str;
    
    while (*end) end++; 
    result = malloc(end - start + 1);
    _memcpy(result, start, end - start); 
    result[end - start] = 0; 
    return result; 
}

return NULL; 
    
}
/**
* _strcat - adds a string
* @dest: detneation
* @src:	sourc
* Return: @dest
*/
char *_strcat(char *dest, char *src)
{
	char *r = dest;

	while (*dest != 0)
		dest++;
	for (; *src; src++, dest++)
		*dest = *src;
	*dest = 0;
	return (r);
}
char * _strappened(char* dest, char ch)
{
    char *r = dest;
    while (*dest != 0)
        dest++;
    *dest = ch;
    dest++;
    dest = 0;
    return (r);
}

char *_strdup(char *s)
{
    size_t len = _strlen(s) + 1;
    char *p = malloc(len);
    if (p == NULL) {
        return NULL;
    }
    memcpy(p, s, len);
    return p;
}


char *_strchr( char *str, int ch) {
    while (*str != '\0') {
        if (*str == (char) ch) {
            return (char *) str;
        }
        str++;
    }
    return NULL;
}
/*
quu..__
 $$$b  `---.__
  "$$b        `--.                          ___.---uuudP
   `$$b           `.__.------.__     __.---'      $$$$"              .
     "$b          -'            `-.-'            $$$"              .'|
       ".                                       d$"             _.'  |
         `.   /                              ..."             .'     |
           `./                           ..::-'            _.'       |
            /                         .:::-'            .-'         .'
           :                          ::''\          _.'            |
          .' .-.             .-.           `.      .'               |
          : /'$$|           .@"$\           `.   .'              _.-'
         .'|$u$$|          |$$,$$|           |  <            _.-'
         | `:$$:'          :$$$$$:           `.  `.       .-'
         :                  `"--'             |    `-.     \
        :##.       ==             .###.       `.      `.    `\
        |##:                      :###:        |        >     >
        |#'     `..'`..'          `###'        x:      /     /
         \                                   xXX|     /    ./
          \                                xXXX'|    /   ./
          /`-.                                  `.  /   /
         :    `-  ...........,                   | /  .'
         |         ``:::::::'       .            |<    `.
         |             ```          |           x| \ `.:``.
         |                         .'    /'   xXX|  `:`M`M':.
         |    |                    ;    /:' xXXX'|  -'MMMMM:'
         `.  .'                   :    /:'       |-'MMMM.-'
          |  |                   .'   /'        .'MMM.-'
          `'`'                   :  ,'          |MMM<
            |                     `'            |tbap\
             \                                  :MM.-'
              \                 |              .''
               \.               `.            /
                /     .:::::::.. :           /
               |     .:::::::::::`.         /
               |   .:::------------\       /
              /   .''               >::'  /
              `',:                 :    .'
                                   `:.:' Tim Park
*/