/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:20:47 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/15 18:37:13 by parksohy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
void	flush_buf(void *buf_line, size_t buf_size)
{
	ft_memset(buf_line, 0, buf_size);
}

void	*buf_is_empty(void *buf_line, size_t buf_size)
{
	size_t	i;

	i = 0;
	while(i < buf_size)
	{
		if (((unsigned char *)buf_line)[i] != 0)
			return (&buf_line[i]);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static void	*buf_line;
	void		*ret_line;
	void		*temp;
	char		*newline_pnt;
	int			index;

	//(re)init buf
	if (buf_line == NULL)
		buf_line = malloc(BUFFER_SIZE + 1);
	if (buf_line == NULL)
		return (NULL);
	//init ret_line
	ret_line = malloc(BUFFER_SIZE + 1);
	if (ret_line == NULL)
		return (NULL);
/*  
**
**
*/
	newline_pnt = ft_strchr((const char *)buf_line, '\n');
	if (newline_pnt != NULL)
	{
		temp = ret_line;
		ret_line = ft_strnappend((char const *)ret_line, (char const *)newline_pnt + 1, ft_strlen(newline_pnt + 1));
		free(temp);
	}
	//read
	if(read(fd, buf_line, BUFFER_SIZE) == -1)
		return (NULL);
	while (ft_strchr((const char *)buf_line, '\n') == NULL)
	{
		temp = ret_line;
		ret_line = ft_strnappend((char const *)ret_line, (char const *)buf_line, ft_strlen(buf_line));
		free(temp);
	}
	newline_pnt = ft_strchr((const char *)buf_line, '\n');
	temp = ret_line;
	ret_line = ft_strnappend((char const *)ret_line, (char const *)buf_line, (void *)newline_pnt - (void *)buf_line);
	free(temp);
	
	return ((char *)ret_line);
}
