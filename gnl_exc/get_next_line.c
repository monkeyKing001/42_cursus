/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:22:44 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/29 21:06:01 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_read_n_fillin_the_buf(char	*buf, int fd)
{
	char	*temp_buf;
	int		read_bytes;

	temp_buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp_buf)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0 && ft_strchr(buf, '\n') == NULL)
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

static char	*ft_flush_out_oneline(char *buf)
{
	char	*temp_buf;
	char	*newline_pnt;
	size_t	new_len;

	newline_pnt = ft_strchr(buf, '\n');
	if (newline_pnt == NULL)
	{
		free(buf);
		return (NULL);
	}
	new_len = ft_strlen(newline_pnt);
	temp_buf = malloc(sizeof(char) * new_len);
	if (!temp_buf)
		return (NULL);
	ft_strlcpy(temp_buf, newline_pnt + 1, new_len);
	free(buf);
	return (temp_buf);
}

static char	*ft_extract_oneline(char	*buf)
{
	char	*newline_pnt;
	char	*ret_line;
	size_t	new_len;

	if (*buf == 0)
		return (NULL);
	newline_pnt = ft_strchr(buf, '\n');
	if (newline_pnt == NULL)
		new_len = ft_strlen(buf) + 1;
	else
		new_len = newline_pnt - buf + 2;
	ret_line = malloc(sizeof(char) * new_len);
	if (!ret_line)
		return (NULL);
	ft_strlcpy(ret_line, buf, new_len);
	return (ret_line);
}

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*ret_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = ft_read_n_fillin_the_buf(buf[fd], fd);
	if (buf[fd] == NULL)
		return (NULL);
	ret_line = ft_extract_oneline(buf[fd]);
	buf[fd] = ft_flush_out_oneline(buf[fd]);
	return (ret_line);
}
