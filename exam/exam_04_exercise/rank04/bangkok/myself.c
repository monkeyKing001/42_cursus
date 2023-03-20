#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
<<<<<<< HEAD
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
=======

int fd;

static void perr(char *s) {
	while (*s)
		write(2, s++, 1);
}

static int cd(char **argv, int i)
{
	if (i != 2)
		return (perr("error : cd: bad arguments\n"), 1);
	else if (chdir(argv[1]) == -1)
		return (perr("error : cd: cannot change directory to "), perr(argv[1]), perr("\n"), 1);
	return (0);
}

static int exec(char **argv, char** envp, int i)
{
	int status;
	int fds[2];
	int pip = (argv[i] && !strcmp(argv[i], "|"));
	// if argv[i] == NULL -> last command -> pip = 0;
	// if argv[i] != NULL && argv[i] == "|" -> pip = 1;
	if (pip && pipe(fds) == -1)
		return (perr("error: fatal\n"), 1);
	int pid = fork();
	if (!pid)
	{
		//child process
		argv[i] = 0;
		if (dup2(fd, 0) == -1 || close(fd) == -1)
			return (perr("error: fatal\n"), 1);
		//if need pipe case(|), fds[1] = 1, 
		if (pip && dup2(fds[1], 1) == -1 || close(fds[0]) == -1 || close(fds[1]) == -1)
			return (perr("error: fatal\n"), 1);
		//execution.
		execve(*argv, argv, envp);
		//cannot exevce
		return (perr("error: cannot execute "), perr(*argv), perr("\n"), 1);
	}
	//parent process
	waitpid(pid, &status, 0);
	if (!pip && dup2(0, fd) == -1)
		return (perr("error: fatal\n"), 1);
	if (pip && (dup2(fds[0], fd) == -1 || close(fds[0]) == -1 || close(fds[1]) == -1))
		return (perr("error: fatal\n"), 1);
>>>>>>> d6bf1afcf169b3454ca22d6a15b097d6feedfe2f
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int argc, char **argv, char **envp)
{
<<<<<<< HEAD
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
=======
	(void)argc;
	int status = 0;
	fd = dup(0);
	while (*argv && (argv + 1))
	{
		argv++;
		int i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(*argv, "cd"))
			status = cd(argv, i);
		else if (i)
			status = exec(argv, envp, i);
		argv += i;
	}
	if (dup2(0, fd) == -1)
		perr("error :fatal\n");
>>>>>>> d6bf1afcf169b3454ca22d6a15b097d6feedfe2f
	return (status);
}
