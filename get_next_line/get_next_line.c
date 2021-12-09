/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:20:47 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/08 17:13:40 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	*ret_line;
	int		index;

	line = (char *)malloc(BUFFER_SIZE);
	if (!line)
		exit(0);
	while (read(fd, line, BUFFER_SIZE))
		ret_line = line;
	return (line);
}
