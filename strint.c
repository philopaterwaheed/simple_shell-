#include "main.h"
int _strlen(char *s)
{
	int i = 0;
	char c = *s;

	while (c != '\0')
		c = *(s + ++i);

	return (i);
}
int* ctoi(char * num)
{
    int i, output = 0, factor = 1;
    int * result; 
    for (i = _strlen(num) - 1; i >= 0; i--)
    {
        if (num[i] >='0' && num[i] <= '9')
        {
            output += (num[i] - '0') * factor;
            factor *= 10;
        }
        else if ((num [i] != '-' && i == 0 ))
        {
            return NULL;
        }
    }
    if (num [0]== '-')
            output *= -1;
    result = malloc(sizeof(int)) ;
    *result = output;
    return (result);
}
int array_size(char **array) {
    int size = 0;
    while (array[size] != NULL) {
        size++;
    }
    return size;
}