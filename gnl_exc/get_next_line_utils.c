/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:47:10 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/29 21:46:12 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *s1, char *s2, size_t len)
{
	size_t	i;

	if (!s2 || len == 0)
		return (0);
	i = 0;
	while (s2[i] && i + 1 < len)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	while (s2[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return (&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret_str;
	size_t	ret_str_i;
	size_t	s_i;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	ret_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret_str)
		return (NULL);
	s_i = 0;
	ret_str_i = 0;
	while (s1[s_i])
		ret_str[ret_str_i++] = s1[s_i++];
	s_i = 0;
	while (s2[s_i])
		ret_str[ret_str_i++] = s2[s_i++];
	ret_str[ret_str_i] = 0;
	free(s1);
	return (ret_str);
}
