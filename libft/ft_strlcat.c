/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:44:39 by dokwak            #+#    #+#             */
/*   Updated: 2021/11/18 13:48:34 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*dest && i < dstsize)
	{
		++i;
		++dest;
	}
	while (*src && i + 1 < dstsize)
	{
		*dest = *src;
		++dest;
		++src;
		++i;
	}
	if (i < dstsize)
		*dest = 0;
	while (*src)
	{
		++i;
		++src;
	}
	return (i);
}
