/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:12:03 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/02 21:54:12 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	get_digit_num(int n)
{
	int	digit_num;

	digit_num = 0;
	if (n < 0)
		digit_num++;
	while (n)
	{
		digit_num++;
		n /= 10;
	}
	return (digit_num++);
}

void	itoa_rec(int n, int index, char **db_pnt)
{
	int		mod;
	int		div;
	char	*pnt;

	if (n == 0)
		return ;
	mod = n % 10;
	div = n / 10;
	if (n < 0)
	{
		mod *= -1;
		div *= -1;
	}
	pnt = *db_pnt;
	pnt[index] = mod + '0';
	itoa_rec(div, --index, db_pnt);
}

char	*ft_itoa(int n)
{
	int		digit_num;
	char	*pnt;

	digit_num = get_digit_num(n);
	pnt = malloc(sizeof(char) * digit_num);
	if (pnt == NULL)
		return (NULL);
	if (n < 0)
		pnt[0] = '-';
	itoa_rec(n, --digit_num, &pnt);
	return (pnt);
}
