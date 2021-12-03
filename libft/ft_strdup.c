/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 03:28:40 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/02 17:58:45 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup_char;

	len = ft_strlen((char *)s);
	dup_char = malloc(sizeof(char) * (len + 1));
	if (dup_char == NULL)
		return (NULL);
	len = -1;
	while (s[++len])
	{
		dup_char[len] = s[len];
	}
	dup_char[len] = 0;
	return (dup_char);
}
