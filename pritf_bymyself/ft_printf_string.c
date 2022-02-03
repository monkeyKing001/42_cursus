/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:44:14 by dokwak            #+#    #+#             */
/*   Updated: 2022/01/31 22:42:59 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_leftmargin_str(t_box *box)
{
	int		ret_len;
	int		i;
	char	padding_char;

	i = -1;
	ret_len = 0;
	padding_char = ' ';
	if (box -> zero_len)
		padding_char = '0';
	if (box -> left_margin > box -> value_len)
		while (++i + box -> value_len < box -> left_margin)
			ret_len += write(1, &padding_char, 1);
	return (ret_len);
}

int	ft_printf_rightmargin_str(t_box *box)
{
	int		ret_len;
	int		i;

	i = -1;
	ret_len = 0;
	if (box -> right_margin > box -> value_len)
		while (++i + box -> value_len < box -> right_margin)
			ret_len += write(1, " ", 1);
	return (ret_len);
}

int	ft_printf_str(t_box *box, char *str)
{
	int ret_len;

	ret_len = 0;
	if (str == NULL)
	{
		box -> value_len = 6;
		str = "(null)";
	}
	else
		str = (char *)box -> value;
	ret_len += ft_printf_leftmargin_str(box);
	ret_len += write(1, str, box -> value_len);
	ret_len += ft_printf_rightmargin_str(box);
	return (ret_len);
}
