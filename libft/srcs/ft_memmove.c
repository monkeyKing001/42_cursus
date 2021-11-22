/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:55:26 by dokwak            #+#    #+#             */
/*   Updated: 2021/11/18 16:46:29 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	buffer;
	size_t			i;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (((unsigned char *)src)[i] != 0 && i < n)
		{
			buffer = ((unsigned char *)src)[i];
			((unsigned char *)dest)[i++] = buffer;
		}
	}
	else
	{
		i = n - 1;
		while (((unsigned char *)src)[i] != 0 && n-- > 0)
		{
			buffer = ((unsigned char *)src)[i];
			((unsigned char *)dest)[i--] = buffer;
		}
	}
	return (dest);
}
