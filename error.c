#include "error.h"
#include "general.h"
#include "text.h"

/**
* selectErrorMessage - Select the message that matches the errorCode
*
* @info: General information about the shell
*
* Return: Error message
**/
char *selectErrorMessage(general_t info)
{
int a, numOptions;
error_t errorMessages[] = {
{_ENOENT, _CODE_ENOENT},
{_EACCES, _CODE_EACCES},
{_CMD_NOT_EXISTS, _CODE_CMD_NOT_EXISTS},
{_ILLEGAL_NUMBER, _CODE_ILLEGAL_NUMBER}
};

numOptions = sizeof(errorMessages) / sizeof(errorMessages[0]);
for (a = 0; a < numOptions; a++)
{
if (info.errorCode == errorMessages[a].code)
{
return (errorMessages[a].message);
}
}

return ("");
}

/**
* printError - Print the error
*
* @info: General information about the shell
**/
void printError(general_t *info)
{
char *errorMessage;
char *number;
char *aux;
int numberSize, messageSize;

number = NULL;
errorMessage = selectErrorMessage(*info);
number = toString(info->numCommands);

numberSize = _strlen(number);
messageSize = _strlen(info->arguments[0]);

aux = malloc(messageSize + numberSize + 3);

aux = _strcpy(aux, info->arguments[0]);
aux = _strcat(aux, ": ");
aux = _strcat(aux, number);

errorMessage = joinWords(aux, info->command, errorMessage, ": ");
printError(errorMessage);

free(errorMessage);
free(number);
free(aux);
}

/**
* printErrorWithExtra - Print the error with extra information
*
* @info: General information about the shell
* @extra: Extra information
**/
void printErrorWithExtra(general_t *info, char *extra)
{
char *errorMessage, *number, *aux, *aux2;
int numberSize, messageSize, extraSize;

number = NULL;
errorMessage = selectErrorMessage(*info);
number = toString(info->numCommands);

numberSize = _strlen(number);
messageSize = _strlen(info->arguments[0]);
extraSize = _strlen(extra);

aux = malloc(messageSize + numberSize + 3);
aux = _strcpy(aux, info->arguments[0]);
aux = _strcat(aux, ": ");
aux = _strcat(aux, number);

aux2 = malloc(_strlen(errorMessage) + extraSize + 3);
aux2 = _strcpy(aux2, errorMessage);
aux2 = _strcat(aux2, ": ");
aux2 = _strcat(aux2, extra);

errorMessage = joinWords(aux, info->command, aux2, ": ");
printError(errorMessage);

free(errorMessage);
free(number);
free(aux);
free(aux2);
}
