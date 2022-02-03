/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:44:39 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/07 15:23:09 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
static void	putnbr_rec(long long lln, int fd)
{
	char		digit;

	if (lln == 0)
		return ;
	putnbr_rec(lln / 10, fd);
	digit = (lln % 10) + '0';
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	lln;

	lln = n;
	if (lln < 0)
	{
		lln *= -1;
		write(fd, "-", 1);
	}
	if (lln == 0)
		write(fd, "0", 1);
	putnbr_rec(lln, fd);
}
