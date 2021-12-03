/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:02:53 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/03 18:01:08 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*pnt;
	size_t	idx;

	if (!s || !f)
		return (NULL);
	pnt = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!pnt)
		return (NULL);
	idx = -1;
	while (s[++idx])
		pnt[idx] = f(idx, s[idx]);
	pnt[idx] = 0;
	return (pnt);
}
