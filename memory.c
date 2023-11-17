#include "memory.h"

/**
* _realloc - Reallocates a memory block using malloc and free
*
* @ptr: Pointer to the memory previously allocated
* @old_size: Size, in bytes, of the allocated space for ptr
* @new_size: New size, in bytes of the new memory block
*
* Return: Memory reallocated
**/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
char *new_ptr, *temp_ptr;
unsigned int index;

if (new_size == old_size)
return (ptr);

if (ptr == NULL)
{
new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);

return (new_ptr);
}

if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}

new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);

temp_ptr = ptr;
for (index = 0; index < old_size; index++)
new_ptr[index] = temp_ptr[index];

free(ptr);

return (new_ptr);
}
