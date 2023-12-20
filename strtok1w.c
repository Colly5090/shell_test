#include "main.h"
/**
 * token_input - function to tokenize user inputs
 * @input: input from users to be tokenized
 * Return: pointer to the new tokens
*/
char **token_input(char *input)
{
	char **new_strings = NULL, *token;
	int numoftoken = 0;
	int x = 0;
	const char *delim = " ";
	char *copy_lineptr = strdup(input);

	if (copy_lineptr == NULL)
	{
		perror("./shell: Memory Error");
		exit(EXIT_FAILURE);
	}
	token = strtok(copy_lineptr, delim);
	while (token != NULL)
	{
		numoftoken++;
		token = strtok(NULL, delim);
	}
	new_strings = malloc(sizeof(char *) * (numoftoken + 1));
	if (new_strings == NULL)
	{
		perror("./shell: Memory Error");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, delim);
	while (token != NULL)
	{
		new_strings[x] = strdup(token);
		if (new_strings[x] == NULL)
		{
			perror("./shell: Memory Error");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
		x++;
	}
	new_strings[x] = NULL;
	free(copy_lineptr);
	return (new_strings);
}
