#include "memory.h"

/**
* freePointer - Free a pointer
*
* @ptr: Pointer to free
**/
void freePointer(void *ptr)
{
if (ptr != NULL)
{
free(ptr);
ptr = NULL;
}

ptr = NULL;
}

/**
* freeDoublePointer - Free a double pointer
*
* @ptr: Double pointer to free
**/
void freeDoublePointer(void **ptr)
{
void **tmp;

for (tmp = ptr; *tmp != NULL; tmp++)
freePointer(*tmp);

freePointer(ptr);
}
