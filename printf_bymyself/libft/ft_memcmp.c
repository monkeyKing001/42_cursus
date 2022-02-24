/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:18:41 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/03 17:32:46 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_uchr;
	unsigned char	*s2_uchr;

	s1_uchr = (unsigned char *)s1;
	s2_uchr = (unsigned char *)s2;
	i = 0;
	while (i < n && s1_uchr[i] == s2_uchr[i])
		i++;
	if (i == n)
		return (0);
	return (s1_uchr[i] - s2_uchr[i]);
}
