#include "main.h"


int main(void)
int working = 1;

while (working == 1)
{
char *line, *line_copy, *token;
char **arguments;
int line_read, i;
/*stores the output of getline which is the size of the string*/
size_t size = 0;
/* to store the size of the line */
size_t words = 0;
/*the number of words in the line*/
pintf("($)");
/* prints the sell sign */
line_read = getline(&line, &size, stdin);
/**
 * takes a  poninter to char* to store  the line and a size_t pointer
 * to store the size of the line and stdin is the way to get it
**/
if (line_read == -1)
{
printf("Exiting shell....\n");
working = -1;
/*makes working  = -1 so that shell exits*/
}
printf("%s\n", line);
line_copy = malloc(sizeof(char) * line_read);
if (!line_copy)
/*on memory falling */
{
printf("Failed to allocate");
working = -1;
}
strcpy(line_copy, line);
/** make a copy of the line to edit it*/
token = strtok(line_copy, " \n");
/**
 *slpits the line on spcases and new lines
 *to get every word and stores it into token
**/
words++;
while (token)
/* keeps looping tell it reaches the end of the line*/
{
token = strtok(NULL, " \n");
/*printf ("%s\n", token ) ;*/
words++;
/* at the end the words number will be +1 the auctual number*/
}
arguments = malloc(words);
/* creates an array of words which will be our arguments  */
token = strtok(line_copy, " \n");
/* repeat the process again  */
for (i = 0 ; token ; i++)
{
arguments[i] = malloc(sizeof(char) * strlen(token));
/* allocate memmory into of the i'th element */
strcpy(arguments[i], token);
/*puts the token inside the array*/
token = strtok(NULL, " \n");
}
arguments [i] = NULL;
/* to free the all the memmoryies */
free(line);
free(line_copy);
free(arguments);
}
return (0);
}
