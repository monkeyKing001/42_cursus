/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:57:01 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/09 15:33:55 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pnt;
	size_t	i;

	if (!s)
		return (NULL);
	pnt = malloc(sizeof(char) * (len + 1));
	if (pnt == NULL)
		return (NULL);
	i = 0;
	if ((size_t)start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	while (i < len && ((char *)s)[start + i] != 0)
	{
		pnt[i] = ((char *)s)[start + i];
		i++;
	}
	pnt[i] = 0;
	return (pnt);
}
