/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:22:12 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/24 01:41:32 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_char(t_box *box)
{
	int		ret_len;
	char	chr;

	chr = (char)(box -> value);
	ret_len = 0;
	ret_len += ft_printf_leftmargin(box);
	ret_len += write(1, &chr, 1);
	ret_len += ft_printf_rightmargin(box);
	return (ret_len);
}

int	ft_printf_leftmargin(t_box *box)
{
	int	ret_len;
	int	i;

	i = -1;
	ret_len = 0;
	if (box -> left_margin > (int) sizeof(char))
		while (++i + (int) sizeof(char) < box -> left_margin)
			ret_len += write(1, " ", 1);
	return (ret_len);
}

int	ft_printf_rightmargin(t_box *box)
{
	int	ret_len;
	int	i;

	i = -1;
	ret_len = 0;
	if (box -> right_margin > (int) sizeof(char))
		while (++i + (int) sizeof(char) < box -> right_margin)
			ret_len += write(1, " ", 1);
	return (ret_len);
}
