#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int ft_perr(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
	{
		while (*arg)
			write(2, arg++, 1);
	}
	write(2, "\n", 1);
	return (1);
}

int ft_execute(int argc, char *argv[], char *envp[], int temp_fd)
{
	argv[argc] = NULL;
	dup2(temp_fd, STDIN_FILENO);
	close(temp_fd);
	execve(argv[0], argv, envp);
	return (ft_perr("error: cannot execute ", argv[0]));
}

int main(int argc, char *argv[], char *envp[])
{
	int i;
	int fd[2];
	int temp_fd;
	(void)argc;

	i = 0;
	temp_fd = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		//count command vector length;
		//argv[i] will be NULL v ";" v "|"
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			//no path given
			if (i != 2)
				ft_perr("error: cd: bad arguments", NULL);
			//cannot change path
			else if (chdir(argv[1]) != 0)
				ft_perr("error: cd: cannot change directory to ", argv[1]);
		}
		//no pipde case;
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			//chid process
			if (fork() == 0)
			{
				if (ft_execute(i, argv, envp, temp_fd))
					return (1);
			}
			else {
			// parent process
				close(temp_fd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				temp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if (fork () == 0)
			{
				//child proc
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(i, argv, envp, temp_fd))
					return (1);
			}
			//parent
			else {
				close(fd[1]);
				close(temp_fd);
				temp_fd = fd[0];
			}
		}
	}
	close(temp_fd);
	return (0);
}
