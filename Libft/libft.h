/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:13:22 by dokwak            #+#    #+#             */
/*   Updated: 2021/11/09 01:54:06 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include<stdlib.h>
# include <string.h>
# include <strings.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(char *str);
ft_memset \
					ft_bzero \
					ft_memcpy \
					ft_memmove \
					ft_strlcpy \
					ft_strlcat \
					ft_toupper \
					ft_tolower \
					ft_strchr \
					ft_strrchr \
					ft_strncmp \
					ft_memchr \
					ft_memcmp \
					ft_strnstr \
					ft_atoi \
					ft_calloc \
					ft_strdup \
					ft_substr \
					ft_strjoin \
					ft_strtrim \
					ft_split \
					ft_itoa \
					ft_strmapi \
					ft_striteri \
					ft_putchar_fd \
					ft_putstr_fd \
					ft_putendl_fd \
					ft_putnbr_fd \

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;
#endif
