#include <unistd.h>
int main(int argc, char **argv, char**envp)
{
	(void)argc;
	int i = 0;
	int temp_fd = dup(0);
	while (argv[i] && argv[i + 1])
	{
		i = 0;
		argv = &argv[i+1];
	}

	return (0);
}
