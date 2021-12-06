/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:12:03 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/06 19:54:50 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
** this func gets digit number of n, n cannot be zero(0) 
** if n is less than 0, allocate one more num for sign '-'
*/
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
	return (digit_num);
}
/*
** div n first to prevent the overflow
** while condition checks if n is 0 or not  
** so, if n is 0, we can not get right digit_num.
*/

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
	itoa_rec(div, index - 1, db_pnt);
}
/*
** if n == 0, return "0" right away
** for correct working of itoa_rec
** allocate digit_num + 1 for last '\0'
** fillin the pnt[] from last index(remainder)
*/

char	*ft_itoa(int n)
{
	int		digit_num;
	char	*pnt;

	if (n == 0)
		return (ft_strdup("0"));
	digit_num = get_digit_num(n);
	pnt = malloc(sizeof(char) * digit_num + 1);
	if (pnt == NULL)
		return (NULL);
	if (n < 0)
		pnt[0] = '-';
	pnt[digit_num] = 0;
	itoa_rec(n, digit_num - 1, &pnt);
	return (pnt);
}
