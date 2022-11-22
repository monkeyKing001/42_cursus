/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:55:09 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/03 17:38:17 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_uchr;	
	unsigned char	*s2_uchr;	

	s1_uchr = (unsigned char *)s1;
	s2_uchr = (unsigned char *)s2;
	i = 0;
	while (i < n && s1_uchr[i] && s2_uchr[i] && s1_uchr[i] == s2_uchr[i])
		i++;
	if (i == n)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
