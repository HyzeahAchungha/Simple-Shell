#include "text.h"
#include "commands.h"
#include "general.h"
#include "memory.h"
#include <signal.h>

/**
* prompt - Print the prompt
*
* @info: Struct of general information
**/
void prompt(general_t *info)
{
if (info->mode == NON_INTERACTIVE)
return;

print("$ ");
}

/**
* read_prompt - Read lines in the prompt
*
* Return: Buffer read or NULL if EOF was found
**/
char *read_prompt()
{
char *buffer;
int result;
size_t size;

buffer = NULL;

result = getline(&buffer, &size, stdin);

if (result == EOF)
{
free_memory_p((void *)buffer);
return (NULL);
}

return (buffer);
}

/**
* start_prompt - Loop reading text
*
* @info: Struct of general information
*
* Return: Buffer read or NULL if EOF was found
**/
void start_prompt(general_t *info)
{
char *buffer;
char **args;
char *path;

signal(SIGINT, sigintHandler);
while (1)
{
prompt(info);

path = _getenv("PATH");
is_current_path(path, info);

info->environment = path;
buffer = read_prompt();
if (buffer == NULL)
{
print(info->mode == INTERACTIVE ? "exit\n" : "");
free(path);
break;
}

info->n_commands++;
if (buffer[0] != '\n')
{
args = split_words(buffer, " \t\n");

info->arguments = args;
info->buffer = buffer;
analyze_patterns(info, args);
analyze(args, info, buffer);

free_memory_pp((void *)args);
}

free_memory_p((void *)buffer);
free_memory_p((void *)path);
}

}

/**
* sigintHandler - Handler for SIGINT
*
* @signal_num: Unused parameter
**/
void sigintHandler(int signal_num)
{
(void)signal_num;

signal(SIGINT, sigintHandler);
print("\n$ ");
fflush(stdout);
}
