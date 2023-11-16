#include "builtins.h"
#include "general.h"

/**
* bin_exit - Implementation of the exit builtin
* Description: Free all the memory used and
* exit with the last status_code
*
* @info: Information about the shell
* @args: Arguments received
**/
void bin_exit(general_t *info, char **args)
{
int statusCode, status;

status = _TRUE;
if (args[1] != NULL)
status = number_controller(info, args[1]);

if (status == _FALSE)
return;

statusCode = info->statusCode;

free_memory_pp((void **)args);
free_memory_p((void *)info->buffer);
free_memory_p((void *)info->environment);
free_memory_p((void *)info);

exit(statusCode);
}

/**
* number_controller - Control the argument of exit
*
* @info: General information about the shell
* @number: Argument of the builtin
*
* Return: If the actual argument is valid, return _TRUE
* if not, return _FALSE
**/
int number_controller(general_t *info, char *number)
{
int num;

num = _atoi(number);

if (num < 0 || contains_letter(number))
{
info->statusCode = 2;
info->errorCode = _CODE_ILLEGAL_NUMBER;
error_extra(info, number);
return (_FALSE);
}

if (num > 255)
info->statusCode = num % 256;
else
info->statusCode = num;

return (_TRUE);
}
