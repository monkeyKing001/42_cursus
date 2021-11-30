/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:51:12 by dokwak            #+#    #+#             */
/*   Updated: 2021/11/30 23:04:15 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	pnt_size;
	char	*pnt;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	pnt_size = s1_len + s2_len + 1;
	pnt = malloc(sizeof(char) * pnt_size);
	if (pnt == NULL)
		return (NULL);
	ft_memset(pnt, 0, sizeof(char) * (pnt_size));
	ft_strlcat(pnt, s1, pnt_size);
	ft_strlcat(pnt, s2, pnt_size);
	return (pnt);
}
