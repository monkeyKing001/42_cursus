/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printphase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:18:46 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/01 14:57:18 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_type(t_options *options, t_box *box, va_list ap)
{
	int ret_len;

	ret_len = 0;
	if (options->type == 'c')
		ret_len += ft_printf_char(box, va_arg(ap, int));
	else if (options -> type == 's')
		ret_len += ft_printf_str(box, va_arg(ap, char *));
	else if (options -> type == 'd' || options -> type == 'i' || options -> type == 'x' || options -> type == 'X')
		ret_len += ft_printf_nbr(box, va_arg(ap, int));
	else if (options -> type == 'p')
		ret_len += ft_printf_pnt(box, va_arg(ap, long long));
	return (ret_len);
}
