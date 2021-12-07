/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 03:15:22 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/07 15:10:46 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
static int	is_space(const char *s)
{
	if (*s == ' ' || *s == '\r' || *s == '\t'
		|| *s == '\f' || *s == '\v' || *s == '\n')
		return (1);
	return (0);
}

static int	is_sig(const char *s, int *sig)
{
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*sig = -1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *s)
{
	long long	ret;
	long long	ret_buf;
	int			sig;

	ret = 0;
	sig = 1;
	while (is_space(s))
		s++;
	if (is_sig(s, &sig))
		s++;
	while (ft_isdigit(*s))
	{
		ret_buf = ret;
		ret = ret * 10 + ((*s - '0') * sig);
		if (sig == 1 && ret_buf > ret)
			return (-1);
		if (sig == -1 && ret_buf < ret)
			return (0);
		s++;
	}
	return (ret);
}
/*
** using ret_buf can check over/underflow
*/
