/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:18:24 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/14 14:52:11 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int		ft_printf_unsigned(t_box *box)
{
	int		ret_len;
	char	*nbr_str;

	ret_len = 0;
	//nbr_str = ft_uitoa((unsigned int)box -> value);
	nbr_str = ull_to_hexbase(box -> value, box -> base);
	if (box -> prefix_len == 2 && box -> value != 0)
	{
		box -> left_margin -= 2;
		box -> right_margin -= 2;
	}
	ret_len += ft_printf_leftmargin_nbr(box);
	ret_len += write(1, nbr_str, box -> value_len);
	ret_len += ft_printf_rightmargin_nbr(box);
	//free itoa box
	free(nbr_str);
	return (ret_len);
}
static int	get_digit_num(unsigned int n)
{
	int	digit_num;

	digit_num = 0;
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

static void	itoa_rec(unsigned int n, int index, char **db_pnt)
{
	unsigned int	mod;
	unsigned int	div;
	char			*pnt;

	if (n == 0)
		return ;
	mod = n % 10;
	div = n / 10;
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

char	*ft_uitoa(unsigned int n)
{
	int		digit_num;
	char	*pnt;

	if (n == 0)
		return (ft_strdup("0"));
	digit_num = get_digit_num(n);
	pnt = malloc(sizeof(char) * digit_num + 1);
	if (pnt == NULL)
		return (NULL);
	pnt[digit_num] = 0;
	itoa_rec(n, digit_num - 1, &pnt);
	return (pnt);
}
