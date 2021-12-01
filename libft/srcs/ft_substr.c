/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:57:01 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/01 11:53:10 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pnt;
	size_t	i;

	i = -1;
	pnt = malloc(sizeof(char) * (len + 1));
	if (pnt == NULL)
		return (NULL);
	while (++i < len && ((char *)s)[start + i] != 0)
		pnt[i] = ((char *)s)[start + i];
	pnt[i] = 0;
	return (pnt);
}
