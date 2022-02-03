/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 23:33:46 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/03 17:44:12 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t cnt, size_t n)
{
	void	*pnt;

	pnt = malloc(n * cnt);
	if (!pnt)
		return (NULL);
	ft_memset(pnt, 0, cnt * n);
	return (pnt);
}
