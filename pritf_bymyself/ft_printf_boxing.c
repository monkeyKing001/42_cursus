/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_boxing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:19:55 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/15 10:06:52 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int		ft_boxing_flag_n_base(t_options *options, t_box *box)
{
	// FLAG "0-*+# " 
	if (ft_strchr(options -> flag, '+'))
	{
		if (box -> value < 0)
			box -> sign = '-';
		else
			box -> sign = '+';
	}
	if (ft_strchr(options -> flag, '#'))
		box -> prefix_len = 2;
	if (options -> type != 'c' && box -> value < 0)
		box -> sign = '-';
	if (options -> type == 'x' || options -> type == 'X' || options -> type == 'p')
	{
		if (options -> type == 'x' || options -> type == 'p')
			ft_strlcpy(box -> base, "0123456789abcdef", 17);
		else
			ft_strlcpy(box -> base, "0123456789ABCDEF", 17);
		box -> base_len = 16;
	}
	if (ft_strchr(options -> flag, ' '))
		if (box -> value >= 0 && (box -> sign == 0))
			box -> sign = ' ';
	return (1);
}

int		ft_boxing_value_len_n_precision(t_options *options, t_box *box)
{
	long long	temp;

	if (!ft_strchr(TYPE, options -> type))
		return (0);
	if (options -> type == 's')
	{
		if (box -> value == 0)
			box -> value = (long long)NULL_STR;
		box -> value_len = (int)ft_strlen((char *)box -> value);
	}
	else if (options -> type != 'c' || options -> type != '%')
	{
		if (box -> value < 0 && (options -> type == 'd' || options -> type == 'i'))
		{
			temp = box -> value * -1;
			box -> sign = '-';
		}
		else
			temp = box -> value;
		box -> value_len = get_malloc_size(temp, box -> base);
	}
	if (options -> precision > -1)
		box -> precision = options -> precision;
	return (1);
}

int		ft_boxing_margin(t_options *options, t_box *box)
{
	if (ft_strchr(options -> flag, '-'))
		box -> right_margin = options -> width;
	else
	{
		box -> left_margin = options ->width;
		if (ft_strchr(options -> flag, '0'))
			box -> zero_len = options -> width;
	}
	//'0' flag -> zero_len = options -> width
	return (1);
}
