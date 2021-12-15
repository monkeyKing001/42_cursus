/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:21:02 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/15 18:37:19 by parksohy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t len;
	
	len = 0;
	while(s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	while (src[i])
		++i;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strnappend(char const *s1, char const *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	pnt_size;
	char	*pnt;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	pnt_size = s1_len + n + 1;
	pnt = malloc(sizeof(char) * pnt_size);
	if (pnt == NULL)
		return (NULL);
	ft_strlcpy(pnt, s1, pnt_size);
	ft_strlcpy(pnt + s1_len, s2, n);
	return (pnt);
}

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)dest)[i++] = (unsigned char)c;
	return (dest);
}
//char	*ft_substr(char const *s, unsigned int start, size_t len)
//{
//	char	*pnt;
//	size_t	i;
//
//	if (!s)
//		return (NULL);
//	pnt = malloc(sizeof(char) * (len + 1));
//	if (pnt == NULL)
//		return (NULL);
//	i = 0;
//	pnt[len] = 0;
//	if ((size_t)start >= ft_strlen((char *)s))
//		return (pnt);
//	while (i < len && ((char *)s)[start + i] != 0)
//	{
//		pnt[i] = ((char *)s)[start + i];
//		i++;
//	}
//	return (pnt);
//}
