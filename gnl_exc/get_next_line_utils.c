/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:47:10 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/20 19:00:11 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	if (!s1)
		s1 = malloc(sizeof(char) * 1);
	if (!s1)
		return (NULL);
	if (!s2 || !s2)
		return (NULL);
		
}

char	*ft_strlcpy(char *s1, char *s2, size_t len)
{
	return (s1);
}
