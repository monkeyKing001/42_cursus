#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

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
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int argc, char **argv, char **envp)
{
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
	return (status);
}
