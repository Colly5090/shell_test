#include "main.h"
/**
 * exec_built_ins - function to execute built-in commands
 * @args: array of commands to be executed
 * Return: nothing
*/
void exec_built_ins(char *args[])
{
	char cwd[1024];
	const char *dir = (args && args[1]) ? args[1] : NULL;
	const char *oldpwd = getenv("OLDPWD");

	if (args == NULL || args[0] == NULL)
	{
		perror("./shell: Invalid");
		return;
	}
	if (_strcmp(args[0], "cd") == 0)
	{
	if (!dir || _strcmp(dir, "~") == 0)
		dir = getenv("HOME");
	else if	(_strcmp(dir, "-") == 0){
		if (oldpwd)
		{
			dir = oldpwd;
		}
		else
		{
			perror("./shell: Cant print");
			return;
		}
	}
		/*dir = getenv("OLDPWD");*/
	if (!dir || chdir(dir) != 0)
		perror("./shell: chdir");
	else if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	} else
		perror("./shell: getcwd");
	} else if (_strcmp(args[0], "pwd") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			write(1, cwd, strlen(cwd));
			write(1, "\n", 1);
		} else
			perror("./shell: getcwd");
	} else if (_strcmp(args[0], "exit") == 0)
		exit(dir ? atoi(dir) : 0);
	else
	{
		write(1, "./shell: Invalid", 16);
		write(1, args[0], strlen(args[0]));
		write(1, "\n", 1);
	}
}
