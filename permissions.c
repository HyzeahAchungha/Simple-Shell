#include "commands.h"
#include "general.h"

/**
* is_executable - Check if a filename have permissions
* for run
*
* @filename: Filename to check
*
* Return: On success, PERMISSIONS
* On error, NON_PERMISSIONS
**/
int is_executable(char *filename)
{
struct stat file_stats;

if (stat(filename, &file_stats) == 0)
{
if (file_stats.st_mode & X_OK)
return (PERMISSIONS);
else
return (NON_PERMISSIONS);
}

return (NON_FILE);
}

/**
* is_file - Check if is a file or binary
* Description: Look for execute permissions and
* if it is a file
*
* @file: File to check
*
* Return: If it is a file with the correct permissions, PERMISSIONS
* If it is a file but does not have permissions or doesn't exist,
* NON_PERMISSIONS
* If it is not a file, NON_FILE
**/
int is_file(char *file)
{
int k, size;

size = _strlen(file);
for (k = 0; k < size; k++)
if (file[k] == '/')
return (is_executable(file));

return (NON_FILE);
}
