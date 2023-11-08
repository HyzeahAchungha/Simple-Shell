#include "commands.h"
#include "builtins.h"
#include "general.h"
#include "memory.h"
#include "text.h"

/**
* analyze - Analyze the arguments
*
* @args: Commands and arguments to execute
* @info: General information about the shell
* @buff: Line read
**/
void analyze(char **args, general_t *info, char *buff)
{
char *command;
int status;

if (*args == NULL || args == NULL)
return;

command = args[0];
info->command = command;
if (check_builtin(info, args) == _TRUE)
return;

status = is_file(command);
if (status == NON_PERMISSIONS)
{
info->status_code = 126;
info->error_code = _CODE_EACCES;
error(info);
return;
}

if (status == 1)
{
execute(command, args, info, buff);
return;
}

if (current_directory(command, args, buff, info) == _TRUE)
return;

info->value_path = which(command, info);
if (info->value_path != NULL)
{
execute(info->value_path, args, info, buff);
free_memory_p((void *) info->value_path);
return;
}

info->status_code = 127;
info->error_code = _CODE_CMD_NOT_EXISTS;
error(info);
}
