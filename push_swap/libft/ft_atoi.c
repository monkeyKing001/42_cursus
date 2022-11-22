/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 03:15:22 by dokwak            #+#    #+#             */
/*   Updated: 2022/07/08 19:11:14 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *s)
{
	long long	ret;
	long long	ret_buf;
	int			sig;

	ret = 0;
	sig = 1;
	while (ft_isspace(s))
		s++;
	if (ft_issign(s, &sig))
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
