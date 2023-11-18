#include "text.h"

/**
* split_words - Split a line into words
*
* @line: Line to split
* @delimiters: Delimiters for splitting the words
*
* Return: Set of words
**/
char **split_words(char *line, const char *delimiters)
{
char **wordArray, **temp, *token;
size_t newArraySize, oldArraySize;

oldArraySize = sizeof(char *);
wordArray = malloc(oldArraySize);
if (wordArray != NULL)
{
newArraySize = 1;
token = strtok(line, delimiters);
while (token)
{
if (token[0] == '#')
break;
temp = _realloc(wordArray, oldArraySize, (newArraySize + 1) * sizeof(char *));
oldArraySize = (newArraySize + 1) * sizeof(char *);
if (temp == NULL)
break;

wordArray = temp;
++newArraySize;

wordArray[newArraySize - 2] = malloc(_strlen(token) + 1);
if (wordArray == NULL)
{
free(wordArray);
free(temp);
}

if (wordArray[newArraySize - 2] != NULL)
_strcpy(wordArray[newArraySize - 2], token);

token = strtok(NULL, delimiters);

temp = NULL;
}

wordArray[newArraySize - 1] = NULL;
}

return (wordArray);
}

/**
* join_words - Join 3 words with a separator
* Description: Result -> w1.sep.w2.sep.w3.sep.nl
* @word1: Word1 to join
* @word2: Word2 to join
* @word3: Word3 to join
* @separator: Separator between the words
*
* Return: Line composed by 3 parts followed by a separator and
* ending with a new line
**/
char *join_words(char *word1, char *word2, char *word3, const char *separator)
{
char *result;
int size_word1, size_word2, size_word3, size_separator;

size_word1 = size_word2 = size_separator = 0;

if (word1 != NULL)
size_word1 = _strlen(word1);
else
word1 = "";

if (word2 != NULL)
size_word2 = _strlen(word2);
else
word2 = "";

if (word3 != NULL)
size_word3 = _strlen(word3);
else
word3 = "";

if (separator != NULL)
size_separator = _strlen((char *)separator);
else
separator = "";

result = malloc(size_word1 + size_word2 + size_word3 +
size_separator + size_separator + 2);
if (result == NULL)
return (NULL);

result = _strcpy(result, word1);
result = _strcat(result, (char *)separator);
result = _strcat(result, word2);
result = _strcat(result, (char *)separator);
result = _strcat(result, word3);
result = _strcat(result, "\n");

return (result);
}
