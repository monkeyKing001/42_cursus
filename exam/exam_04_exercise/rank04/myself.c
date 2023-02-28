#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int write_err(char *err_str, char *argv)
{
	while (*err_str)
		write(2, err_str++, 1);
	while (*argv)
		write(2, argv++, 1);
	write(2, "\n", 1);
	return (0);
}

int ft_exe(int argc, char** argv, char **envp, int temp_fd)
{
	return (0);
}
int	main(int argc, char **argv, char **envp)
{
	return (0);
}

