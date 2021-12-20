/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:22:44 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/20 19:00:14 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*read_n_fillin_the_buf(char	*buf, int fd)
{
	return (NULL);
}

static char	*flush_out_oneline(char *buf)
{
	return (NULL);
}

static char	*extract_oneline(char	*buf)
{
	char	newline_pnt;

	pnt = ft_strchr(buf, '\n');
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*ret_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = read_n_fillin_the_buf(buf[fd], fd);
	if (buf[fd] == NULL)
		return (NULL);
	ret_line = extract_oneline(buf[fd]);
	buf[fd] = flush_out_oneline(buf[fd]);
	return (ret_line);
}
