/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:41:00 by dokwak            #+#    #+#             */
/*   Updated: 2021/11/18 15:54:47 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest != src && n != 0)
	{
		while (i < n && ((unsigned char *)src)[i] != 0)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i++];
	}
	return (dest);
}
