#include "commands.h"
#include "general.h"
#include "memory.h"
#include "text.h"

/**
* analyze_patterns - Entry Point
* @info: input
* @arguments: input
**/

void analyze_patterns(general_t *info, char **arguments)
{
int c;

for (c = 0; arguments[c] != NULL; c++)
arguments[c] = pattern_handler(info, arguments[c]);
}

/**
* pattern_handler - Entry Point
* @info: input
* @string: input
* Return: string
**/

char *pattern_handler(general_t *info, char *string)
{
int c;

for (c = 0; string[c] != '\0'; c++)
{
if (string[c] == '$' && string[c + 1] != '\0')
string = replace_value(info, &c, string);
}

return (string);
}

/**
* replace_value - Entry Point
* @info: input
* @index: input
* @string: input
* Return: string
**/

char *replace_value(general_t *info, int *index, char *string)
{
int i, new_size, old_size;
char *value;

i = *index;
i++;

value = replacement(info, index, string + i);
if (value == NULL)
{
string = _strcpy(string, "");

return (string);
;
}

old_size = _strlen(string);
new_size = _strlen(value) + 1;

string = _realloc(string, old_size, new_size);
string = _strcpy(string, value);

free_memory_p(value);
*index = i;
return (string);
}
