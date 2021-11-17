/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 01:07:18 by dokwak            #+#    #+#             */
/*   Updated: 2021/11/18 01:10:04 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>
int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	return (0);
}

int	ft_isalpha(int c)
{
	if ('a' <= c && c <= 'z')
		return (c);
	if ('A' <= c && c <= 'Z')
		return (c);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (c);
	return (0);
}
