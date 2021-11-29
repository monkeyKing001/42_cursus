/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 23:33:46 by dokwak            #+#    #+#             */
/*   Updated: 2021/11/29 22:10:49 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t cnt, size_t n)
{
	void	*pnt;

	if (cnt == 0 || n == 0)
		return (NULL);
	pnt = malloc(n * cnt);
	ft_memset(pnt, 0, cnt * n);
	return (pnt);
}
