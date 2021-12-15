/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:20:57 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/15 17:57:22 by parksohy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096 
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX	4096 
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *dest, int c, size_t n);
size_t 	ft_strlcpy(char *dst, const char *src, size_t dst_size);
size_t	ft_strlen(char *s);
char	*ft_strnappend(char const *dest, char const *src, size_t n);
//char	*ft_substr(char const *s, unsigned int start, size_t len);
//char	**ft_newline_split(char *s);
#endif
