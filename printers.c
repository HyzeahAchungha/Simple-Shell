#include "general.h"
#include "text.h"
#include <unistd.h>

/**
* _putchar_to_fd - Print a character to a specific file
* descriptor
*
* @chr: Character to print
* @file_desc: Place to print the character
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
**/
int _putchar_to_fd(char chr, int file_desc)
{
return (write(file_desc, &chr, 1));
}


/**
* print_to_fd - Print a string
*
* @str: String to print in the file descriptor specified
* @file_desc: File descriptor to print
*
* Return: On success, the number of bytes printed.
* On error, -1 is returned, and errno is set appropriately.
**/
int print_to_fd(char *str, int file_desc)
{
int size;

size = _strlen(str);

return (write(file_desc, str, size));
}
