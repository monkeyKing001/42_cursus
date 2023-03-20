#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
int fd;

static void ft_perr(char *err)
{
	while (*err)
		write(2, err++, 1);
}

static int ft_cd(int argc_a, char **argv_a)
{
	if (argc_a != 2)
		return (ft_perr("error: cd: bad arguments\n"), 1);
	if (chdir(argv_a[1]) == -1)
		return (ft_perr("error: cd: cannot change directory to "), ft_perr(argv_a[1]), ft_perr("\n"), 1);
	return (0);
}

static int ft_exec(int argc_a, char **argv_a, char **envp_a)
{
	int pipe_on = (argv_a[argc_a] && strcmp(argv_a[argc_a], "|") == 0);
	int status;
	int fds[2];
	int pid;
	if (pipe_on && pipe(fds) == -1)
		return (ft_perr("error: fatal\n"), 1);
	pid = fork();
	if (pid == 0)
	{
		argv_a[argc_a] = NULL;
		if (dup2(fd, STDIN_FILENO) == -1 || close(fd))
			return (ft_perr("error: fatal\n"), 1);
		if (pipe_on && (dup2(fds[1], STDOUT_FILENO) == -1 || close(fds[1]) == -1 || close(fds[0]) == -1))
			return (ft_perr("error: fatal\n"), 1);
		execve(argv_a[0], argv_a, envp_a);
		return (ft_perr("error: cannot execute "), ft_perr(argv_a[0]), ft_perr("\n"), 1);
	}
	waitpid(pid, &status, 0);
	if (!pipe_on && dup2(STDIN_FILENO, fd) == -1)
		return (ft_perr("error: fatal\n"), 1);
	if (pipe_on && (dup2(fds[0], fd) == -1 || close(fds[0]) == -1 || close(fds[1]) == -1))
		return (ft_perr("error: fatal\n"), 1);
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int argc, char **argv, char **envp)
{
	(void) argc;
	int i= 0;
	int status = 0;
	fd = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
			ft_cd(i, argv);
		else if (i)
			ft_exec(i, argv, envp);
	}
	if (dup2(0, fd) == -1)
		return (ft_perr("error: fatal\n"), 1);
	close(fd);
	return (status);
}
