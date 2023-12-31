#include "main.h"
/**
 * getpath - function that handles PATH
 * @inputs: command from user to search path
 * Return: nothing
*/
char *getpath(char *inputs)
{
	char *envar, *copyEnvar, *tokenpath, *pathfile;
	int inputlength, lengthofdir;
	struct stat buffer;

	envar = getenv("PATH");
	if (envar)
	{
		copyEnvar = strdup(envar);
		inputlength = _strlen(inputs);
		tokenpath = strtok(copyEnvar, ":");
		while (tokenpath != NULL)
		{
			lengthofdir = _strlen(tokenpath);
			pathfile = malloc(inputlength + lengthofdir + 2);
			if (pathfile == NULL)
			{
				perror("./shell: Memory allocation error");
				exit(1);
			}
			strcpy(pathfile, tokenpath);
			_strcat(pathfile, "/");
			_strcat(pathfile, inputs);
			pathfile[inputlength + lengthofdir + 1] = '\0';
			if (stat(pathfile, &buffer) == 0)
			{
				free(copyEnvar);
				return (pathfile);
			}
			else
			{
				free(pathfile);
				tokenpath = strtok(NULL, ":");
			}
		}
		free(copyEnvar);
		if (stat(inputs, &buffer) == 0)
			return (inputs);
		return (NULL);
	}
	return (NULL);
}
