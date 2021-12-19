#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*ret_line;
	int		fd;

	fd = open(argv[1], O_RDWR);
	ret_line = get_next_line(fd);
	printf("%s\n", ret_line);
	while (ret_line)
	{
		printf("%s\n", ret_line);
		ret_line = get_next_line(fd);
	}
	return (0);
}
