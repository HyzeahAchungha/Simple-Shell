#include "commands.h"
#include "general.h"
#include "memory.h"

/**
* executeCommand - Execute a command in another process
*
* @command: Command to execute
* @args: Arguments of the @command
* @info: General info about the shell
* @buffer: Line read
**/
void executeCommand(char *command, char **args, general_t *info, char *buffer)
{
int statusCode;
pid_t processId;

processId = fork();
if (processId == 0)
{
execve(command, args, environ);
perror("./sh");

freeMemoryPP((void *)args);

if (info->pathValue != NULL)
{
free(info->pathValue);
info->pathValue = NULL;
}

free(info);
free(buffer);
exit(1);
}
else if (processId > 0)
{
waitpid(processId, &statusCode, 0);
if (WIFEXITED(statusCode))
info->statusCode = WEXITSTATUS(statusCode);
}
}

/**
* execute_Directory - Execute the command if the order requires
*
* @cmd: Command to execute
* @args: Arguments of the @cmd
* @buffer: Line read
* @info: General info about the shell
*
* Return: Status of the operations
**/
int execute_Directory(char *cmd, char **args, char *buffer, general_t *info)
{
if (info->isCurrentDir == _FALSE)
return (_FALSE);

if (isExecutable(cmd) == PERMISSIONS)
{
executeCommand(cmd, args, info, buffer);
return (_TRUE);
}

return (_FALSE);
}
