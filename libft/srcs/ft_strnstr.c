/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 23:25:52 by dokwak            #+#    #+#             */
/*   Updated: 2021/11/28 23:25:56 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[++i] != 0)
	{
		j = 0;
		while (haystack[i + j] == needle[i + j] && j < n)
		{
			if (needle[i + j] == 0 && j == n - 1)
				return (&((char *)haystack)[i]);
			j++;
		}
	}
	return (NULL);
}
