#include "text.h"

/**
* string_length - Return the length of a string
*
* @str: String to calculate length
*
* Return: Length of the string
**/
int string_length(char *str)
{
int k;

for (k = 0; str[k] != '\0'; k++)
;

return (k);
}

/**
* string_concatenate - Concatenates two strings
*
* @dest: String to concatenate
* @src: Source string
*
* Return: A concatenated string
*/
char *string_concatenate(char *dest, char *src)
{
int dest_length, k;

dest_length = string_length(dest);

for (k = 0; src[k] != '\0'; k++, dest_length++)
dest[dest_length] = src[k];

dest[dest_length] = '\0';

return (dest);
}

/**
* string_copy - Copy a string to another
*
* @dest: Destination copy
* @src: Source for copy
*
* Return: Return the value of dest
*/
char *string_copy(char *dest, char *src)
{
int k;

for (k = 0; src[k] != '\0'; k++)
dest[k] = src[k];

dest[k] = '\0';

return (dest);
}

/**
* string_duplicate - Pointer to a newly allocated space in memory
*
* @str: String to copy
*
* Return: String copied
**/
char *string_duplicate(char *str)
{
int size, k;
char *dest;

if (str == NULL)
return (NULL);

size = string_length(str) + 1;
dest = malloc(size *sizeof(char));
if (dest == NULL)
return (NULL);

for (k = 0; k < size; k++)
*(dest + k) = *(str + k);

return (dest);
}

/**
* string_compare - Compare two strings
*
* @s1: String 1
* @s2: String 2
*
* Return: Integer
*/
int string_compare(char *s1, char *s2)
{
int k;

for (k = 0; s1[k] != '\0'; k++)
{
if (s1[k] != s2[k])
return (s1[k] - s2[k]);
}

return (0);
}
