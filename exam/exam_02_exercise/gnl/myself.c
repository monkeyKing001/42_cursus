#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
char	*gnl(int fd);
char	*res_line(int index, int fd);
char	*gnl(int fd)
{
	return (res_line(0, fd));
}
char	*res_line(int index, int fd)
{
	char	buf;
	int		rb;
	char	*line;

	rb = read(fd, &buf, 1);
	if (rb < 0 || (rb == 0 && index == 0))
		return (0);
	if (rb == 0 || buf == '\n')
		line = malloc(index + 2);
	else
		line = res_line(index + 1, fd);
	if (line)
	{
		line[index] = buf;
		line[index + 1] = line[index + 1] * (buf != '\n');
		return (line);
	}
	return (line);
}
