/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:26:36 by dokwak            #+#    #+#             */
/*   Updated: 2022/11/12 22:01:54 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// if (read fail or (ready_bytes == 0 and size == 0)
// return NULL
// if (read_bytes == 0 or current buffer_char is '\n')
// malloc(size + 2)
char	*res_line(size_t size_n_index, int fd)
{
	char	*line;
	char	buffer_char;
	char	read_bytes;

	line = 0;
	buffer_char = 0;
	read_bytes = read(fd, &buffer_char, 1);
	//null string return case;
	if (read_bytes < 0 || (read_bytes == 0 && size_n_index == 0))
		return (0);
	//when meet \n char or 0
	if (read_bytes == 0 || buffer_char == '\n')
		line = malloc(size_n_index + 2);
	//when meet normal char not \n
	else
		line = res_line(size_n_index + 1, fd);
	//insert char in line
	if (line)
	{
		//input buffer case
		line[size_n_index] = buffer_char;
		//input exit char (0) when buffer_case is \n
		line[size_n_index + 1] = line[size_n_index + 1] * (buffer_char != '\n');
		return (line);
	}
	return (line);
}

char	*gnl(int fd)
{
	if (fd < 0)
		return (0);
	return (res_line(0, fd));
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("./test.txt", O_RDONLY);
	str = gnl(fd);
	printf("%s", str);
}
