#include "main.h"
/**
 * _strcmp - function to compare s1 to s2
 * @s1: first string
 * @s2: second string
 * Return: nothing
*/
int _strcmp(const char *s1, const char *s2)
{
	int x;

	x = 0;
	while (s1[x] != '\0' && s2[x] != '\0')
	{
	if (s1[x] != s2[x])
		{
		return (s1[x] - s2[x]);
		}
	x++;
	}
	return (0);
}

/**
  * _strlen - to check the length of strings
  * @str: string to check its length
  * Return: numb of the string
  */
int _strlen(char *str)
{
	int x = 0;

	if (str == NULL)
		return (0);
	while (*str++)
		x++;
	return (x);
}

/**
 * _strcat - to concantenates two strings
 * @dest: destination string
 * @sour: source string
 * Return: pointer to the new string
*/
char *_strcat(char *dest, const char *sour)
{
	char *result = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*sour != '\0')
	{
		*dest = *sour;
		dest++;
		sour++;
	}
	*dest = '\0';
	return (result);
}
