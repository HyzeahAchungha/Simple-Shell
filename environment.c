#include "commands.h"
#include "general.h"
#include "text.h"
#include <string.h>
#include <sys/cdefs.h>
#include <unistd.h>

/**
* getEnvironmentVariable - Get an environment variable
*
* @name: Environment variable to get
*
* Return: On success, value of @name
* On error, NULL
**/
char *getEnvironmentVariable(const char *name)
{
char **env;
char *aux, *token, *value;
int size;

size = stringLength((char *)name);

for (env = environ; *env; ++env)
{
aux = stringDuplicate(*env);

token = strtok(aux, "=");
if (token == NULL)
{
free(aux);
return (NULL);
}

if (stringLength(token) != size)
{
free(aux);
continue;
}

if (stringCompare((char *)name, aux) == 0)
{
token = strtok(NULL, "=");
value = stringDuplicate(token);

free(aux);
return (value);
}

free(aux);
}

return (NULL);
}

/**
* findPath - Find the directory needed
*
* @filename: Command received
* @info: General info about the shell
*
* Return: Pointer to string with found path or NULL in failure.
*/
char *findPath(char *filename, general_t *info)
{
char *path, *tmpPath, *token;
char *slash;
int size;

(void)info;

path = getEnvironmentVariable("PATH");
if (path == NULL)
return (NULL);
token = strtok(path, ":");
size = stringLength(filename) + 2;
slash = malloc(size *sizeof(char));
slash = stringCopy(slash, "/");
slash = stringConcat(slash, filename);

while (token != NULL)
{
tmpPath = malloc(stringLength(token) + size);
tmpPath = stringCopy(tmpPath, token);
tmpPath = stringConcat(tmpPath, slash);

if (isExecutable(tmpPath) == PERMISSIONS)
{
free(slash);
free(path);
return (tmpPath);
}
token = strtok(NULL, ":");

free(tmpPath);
}

free(path);
free(slash);

return (NULL);
}

/**
* checkCurrentPath - Check the order of the path
*
* @path: PATH to check
* @info: General info about the shell
**/
void checkCurrentPath(char *path, general_t *info)
{
info->isCurrentPath = _FALSE;
if (path == NULL)
return;

if (path[0] == ':')
info->isCurrentPath = _TRUE;
}

/**
* printFullEnvironment - Print all the environment variables
**/
void printFullEnvironment(void)
{
char **tmp;
int c;

for (c = 0, tmp = environ; tmp[c] != NULL; c++)
{
print(tmp[c]);
putchar('\n');
}
}
