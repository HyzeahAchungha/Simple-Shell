#include "general.h"
#include "text.h"
#include "commands.h"

/**
* replacement - Entry point
* @info: input
* @idx: input
* @str: input
* Return: string
**/

char *replacement(general_t *info, int *idx, char *str)
{
char *tmp;
char symbol;

(void)idx;

symbol = *str;
if (symbol != '?' && symbol != '$')
{
tmp = replace_env(info, str);
return (tmp);
}

tmp = (symbol == '$') ? to_string(info->pid) :
to_string(info->status_code);

return (tmp);
}

/**
* replace_env - Entry Point
* @info: input
* @environment: input
* Return: string
**/

char *replace_env(general_t *info, char *environment)
{
char *env;

(void)info;

env = _getenv(environment);
if (env != NULL)
return (env);

return (NULL);
}
