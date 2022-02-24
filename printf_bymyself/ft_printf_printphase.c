/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printphase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:18:46 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/23 21:57:05 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_type(t_options *options, t_box *box)
{
	int	ret_len;

	ret_len = 0;
	if (options->type == 'c' || options -> type == '%')
		ret_len += ft_printf_char(box);
	else if (options -> type == 's')
		ret_len += ft_printf_str(box);
	else if (options -> type == 'd' || options -> type == 'i')
		ret_len += ft_printf_nbr(box);
	else if (options -> type == 'x'
		|| options -> type == 'X'
		|| options -> type == 'u')
		ret_len += ft_printf_unsigned(box);
	else if (options -> type == 'p')
		ret_len += ft_printf_pnt(box);
	return (ret_len);
}
