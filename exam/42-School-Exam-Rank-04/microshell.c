#include "microshell.h"

int	write_error(char *string, char *argv)
{
	while (*string)
		write(2, string++, 1);
	while (*argv)
		write(2, argv++, 1);
	write(2, "\n", 1);
	return (1);
}

int	ft_exe(char **argv, int i, int temporary_file_descriptor, char **environment_variables)
{
	dup2(temporary_file_descriptor, 0);
	close(temporary_file_descriptor);
	//;, NULL -> NULL
	argv[i]= NULL;
	if(execve(argv[0], argv, environment_variables) == -1)
		return(write_error("error: cannot execute ", argv[0]));
	return (0);
}

//cd ../exam_02
//ls
//wc -l
int main(int argc, char **argv, char **environment_variables)
{
	(void)argc;
	int i = 0;
	int temporary_file_descriptor = dup(0);

	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		//command exist check
		//move i until argv[i](string) is "|" or ";" 
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		//in "./microshell wc -l ; ls -al" i = 3(;)
		if (strcmp("cd", argv[0]) == 0)
		{
			//no path arg
			if (i != 2)
				write_error("error: cd: bad arguments", NULL);
			//change directory
			else if (chdir(argv[1]) == -1)
				write_error("error: cd: cannot change directory to ", argv[1]);
		}
		//command exist and it is not cd
		//string argv[i]
		//argv[0] ~ argv[i] -> one process chunk
		else if (i != 0 && (argv[i] == NULL || strcmp(";", argv[i]) == 0))
		{
			if (!fork())
			{
				//fork`child
				if (ft_exe(argv, i, temporary_file_descriptor, environment_variables))
					return (1);
			}
			else
				//parent
				waitpid(-1,NULL,0);
		}
	}
}
