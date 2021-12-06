/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:21:15 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/06 19:54:32 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)dest)[i++] = (unsigned char)c;
	return (dest);
}
/*
** only when c is 0 or -1 function would work correctly 
** set memory by 1byte (00 00 00 00)
** setting one block memory with 1 (= c) will work as '00 00 00 01'
** 0, -1 will works as each '00 00 00 00', '11 11 11 11'
*/
