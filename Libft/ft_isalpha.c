/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:55:29 by dokwak            #+#    #+#             */
/*   Updated: 2021/11/18 01:06:22 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

int	ft_isalpha(int c)
{
	if ('a' <= c && c <= 'z')
		return (c);
	if ('A' <= c && c <= 'Z')
		return (c);
	return (0);
}
