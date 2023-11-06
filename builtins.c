#include "builtins.h"

/**
* builtins - Check and execute the builtins
*
* @shellInfo: Information about the shell
* @args: Commands and arguments
*
* Return: If the command passed is a built-in,
* return _TRUE; if not, return _FALSE.
**/
int builtins(general_t *shellInfo, char **args)
{
int statusCode;

statusCode = check_builtin(shellInfo, args);
if (statusCode == _FALSE)
return (_FALSE);

return (_TRUE);
}


/**
* check_builtin - Check if the actual command is a built-in or not
*
* @shellInfo: General information about the shell
* @args: Arguments of the command
*
* Return: If the command is an actual built-in, return _TRUE;
* if not, return _FALSE.
**/
int check_builtin(general_t *shellInfo, char **args)
{
int i, size;
builtin_t builtins[] = {
{"exit", bin_exit},
{"env", bin_env}
};

size = sizeof(builtins) / sizeof(builtins[0]);
for (i = 0; i < size; i++)
{
if (_strcmp(shellInfo->command, builtins[i].command) == 0)
{
builtins[i].func(shellInfo, args);
return (_TRUE);
}
}

return (_FALSE);
}
