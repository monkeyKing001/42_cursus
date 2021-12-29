/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:22:50 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/29 12:42:26 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *s1, char *s2, size_t len);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);

#endif
