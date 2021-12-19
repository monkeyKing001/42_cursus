/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:20:47 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/20 01:16:33 by gwagdong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
static char	*ft_flush_out_oneline(char *buf)
{
	char	*newline_pnt;
	char	*ret_str;
	size_t	len;

	newline_pnt = ft_strchr(buf, '\n');
	if (newline_pnt == NULL)
	{
		free(buf);
		return (NULL);
	}
	else
		len = ft_strlen(buf) - (newline_pnt - buf);
	ret_str = malloc(sizeof(char) * len);
	if (!ret_str)
		return (NULL);
	ft_strlcpy(ret_str, newline_pnt + 1, len);
	free(buf);
	return (ret_str);
}

static char	*ft_extract_line(char *buf)
{
	char	*newline_pnt;
	char	*ret_str;
	size_t	len;

	newline_pnt = ft_strchr(buf, '\n');
	if (newline_pnt == NULL)
		len = ft_strlen(buf) + 1;
	else
		len = newline_pnt - buf + 2;
	if (len == 0)
		return (NULL);
	ret_str = malloc(sizeof(char) * len);
	if (!ret_str)
		return (NULL);
	ft_strlcpy(ret_str, buf, len);
	return (ret_str);
}
/*
** if) newline_pnt == NULL 
** ret_str size is pnt - buf + 1(null char)
** else) 
** ret_str size is pnt - buf + 1(\n) + 1(null char)
*/

static char	*ft_read_fd_fill_buf(char *buf, int fd)
{
	char	*temp_buf;
	int		read_bytes;

	temp_buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp_buf)
		return (NULL);
	read_bytes = 1;
	while (read_bytes && !ft_strchr(buf, '\n'))
	{
		read_bytes = read(fd, temp_buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(temp_buf);
			return (NULL);
		}
		temp_buf[read_bytes] = 0;
		buf = ft_strjoin(buf, temp_buf);
	}
	free(temp_buf);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*ret_line;
	static char	*buf_line[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	buf_line[fd] = ft_read_fd_fill_buf(buf_line[fd], fd);
	if (!buf_line[fd])
		return (0);
	ret_line = ft_extract_line(buf_line[fd]);
	buf_line[fd] = ft_flush_out_oneline(buf_line[fd]);
	return ((char *)ret_line);
}
/*
** you can check OPEN_MAX with command $> ulimit -n
** fill up the buffer from until buffer contains at least one of  '\n'
** extract one line from buffer 
** flush out one line from buffer 
** 
*/
