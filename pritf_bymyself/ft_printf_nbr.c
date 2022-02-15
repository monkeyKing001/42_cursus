/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:48:50 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/15 10:26:05 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_nbr(t_box *box)
{
	int		ret_len;
	char	*nbr_str;

	ret_len = 0;
	//if value is minus, make it plus
	if (box -> sign)
	{
		box -> left_margin -= 1;
		box -> right_margin -= 1;
		if (box -> sign == '-')
			box -> value *= -1;
	}
	nbr_str = ft_uitoa(box -> value);
//	printf("\nvalue_len : %d precision : %d zero_len : %d\n", box -> value_len, box -> precision, box -> zero_len);
	ret_len += ft_printf_leftmargin_nbr(box);
	ret_len += write(1, nbr_str, box -> value_len);
	ret_len += ft_printf_rightmargin_nbr(box);
	//free itoa box
	free(nbr_str);
	return (ret_len);
}

int	ft_printf_leftmargin_nbr(t_box *box)
{
	int		ret_len;
	int		i;
	char	padding_char;

	i = -1;
	ret_len = 0;
	padding_char = ' ';
	//padding char become '0' if box -> zero
	if (box -> precision != -1 && box -> value == 0)
		box -> value_len = 0;
	if (box -> zero_len && box -> precision == -1)
		padding_char = '0';
	box -> zero_len = 0;
	if (box -> precision - box -> value_len > 0)
		box -> zero_len += box -> precision - box -> value_len;
	//print sign and margin
	if (box -> sign)
	{
		if(padding_char == '0')
		{
			ret_len += write(1, &box -> sign, 1);
			while (++i + (box -> value_len) + (box -> zero_len) < box -> left_margin)
				ret_len += write(1, &padding_char, 1);
		}
		else if (padding_char == ' ')
		{
			while (++i + (box -> value_len) + (box -> zero_len) < box -> left_margin)
				ret_len += write(1, &padding_char, 1);
			ret_len += write(1, &box -> sign, 1);
		}
	}
	//print margin with out sign
	else
	{
		while (++i + (box -> value_len) + (box -> zero_len) < box -> left_margin)
			ret_len += write(1, &padding_char, 1);
	}
	//precision zero(if need)
	if (box -> prefix_len && box -> value != 0)
	{
		if (ft_strchr(box -> base, 'a'))
			ret_len += write(1, "0x", 2);
		else if (ft_strchr(box -> base, 'A'))
			ret_len += write(1, "0X", 2);
	}
	i = -1;
	while (++i < box -> zero_len)
		ret_len += write(1, "0", 1);
	return (ret_len);
}

int	ft_printf_rightmargin_nbr(t_box *box)
{
	int		ret_len;
	int		i;

	i = -1;
	ret_len = 0;
	while (++i + (box -> value_len) + (box -> zero_len) < box -> right_margin)
		ret_len += write(1, " ", 1);
	return (ret_len);
}
