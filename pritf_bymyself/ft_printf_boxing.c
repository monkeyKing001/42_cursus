/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_boxing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:19:55 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/01 15:12:04 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// value assignment
int		ft_printf_boxing(t_options *options, t_box *box, va_list ap)
{
	va_list	va_cpy_pnt;
	
	if (!ft_strchr(TYPE, options -> type) || !options_flag_check(options))
		return (0);
	//value byte and original value assignment
	va_copy(va_cpy_pnt, ap);
	if (options -> type == 'c' || options -> type == 'd' || options -> type == 'i'\
		|| options -> type == 'u' || options -> type == 'x' || options -> type == 'X')
		box -> value = va_arg(va_cpy_pnt, int);
	else if(options -> type == 's' || options -> type == 'p')
		box -> value = va_arg(va_cpy_pnt, long long);
	//margin assignment
	if (!ft_boxing_margin(options, box))
		return (0);
	//flag assignment
	if (!ft_boxing_flag(options, box))
		return (0);
	//precision assignment
	if (!ft_boxing_precision(options, box))
		return (0);
	va_end(va_cpy_pnt);
	return (1);
}
// margin assignment
int		ft_boxing_margin(t_options *options, t_box *box)
{
	if (ft_strchr(options -> flag, '-'))
		box -> right_margin = options -> width;
	else
		box -> left_margin = options ->width;
	if (ft_strchr(options -> flag, '0') && !ft_strchr(options -> flag, '-'))
		box -> zero_len = box -> left_margin;
	return (1);
}
// flag assignment
int		ft_boxing_flag(t_options *options, t_box *box)
{
	// FLAG "0-*+# " 
	if (ft_strchr(options -> flag, '+'))
		box -> sign = '+';
	if (box -> value < 0)
	{
		box -> sign = '-';
		box -> value *= -1;
	}
	if (ft_strchr(options -> flag, '#'))
		box -> prefix_len = 2;
	if (options -> type == 'x' || options -> type == 'X')
	{
		box -> prefix_len = 2;
		if (options -> type == 'x')
			ft_strlcpy(box -> base, "0123456789abcdef", 17);
		else
			ft_strlcpy(box -> base, "0123456789ABCEDF", 17);
		box -> base_len = 16;
	}
	return (1);
}
// (visual mode) <g> <C-g> -> line number
// precision assignment
int		ft_boxing_precision(t_options *options, t_box *box)
{
	if (options -> type == 's')
	{
		if (options -> precision > -1 &&
			options -> precision <= (int)ft_strlen((char *)box -> value))
			box -> value_len = options -> precision;
		else
			box -> value_len = (int)ft_strlen((char *)box -> value);
	}
	else if (options -> type == 'd' || options -> type == 'i' ||  options -> type == 'x' ||  options -> type == 'X')
	{
		//use "base itoa"
		//value can not be smaller than 0
		if (box -> base_len == 10 || box -> base_len == 16)
		{
			if (options -> precision > -1 &&
				options -> precision <= get_malloc_size(box -> value, box->base))
				box -> value_len = options -> precision;
			else
				if (box -> base_len == 10 || box -> base_len == 16)
					box -> value_len = get_malloc_size(box -> value, box->base);
		}
		else
			return (0);
	}
	return (1);
}
