/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_preprocess.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:03:53 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/10 20:01:18 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
t_options	*ft_read_ap(t_options *options, va_list ap)
{
	if (options->precision == -1)
	{
		options->width = va_arg(ap, int);
		if (options->width < 0)
		{
			ft_strlcat(options -> flag, "-", ft_strlen(options -> flag) + 2);
			options->width *= -1;
		}
	}
	else
		options->precision = va_arg(ap, int);
	if (options ->precision < 0)
		options -> precision = -1;
	return (options);
}

t_options	*ft_read_options(t_options *options, va_list ap, const char *format, int i)
{	
	// if -, 0 both appear, 0 is ignored.
	if (format[i] == '*')
		options = ft_read_ap(options, ap);
	else if (format[i] == '0' && options -> width == 0 && options -> precision == -1)
	{
		if (!ft_strchr(options -> flag, '0'))
			ft_strlcat(options -> flag, "0", ft_strlen(options -> flag) + 2);
	}
	else if (ft_isdigit(format[i]) && options -> precision == -1)
		options -> width = (options -> width * 10) + (format[i] - '0');
	else if (ft_isdigit(format[i]))
		options -> precision = (options -> precision * 10) + (format[i] - '0');
	else if (format[i] == '.')
		options -> precision = 0;
	else if (ft_strchr(FLAG, format[i]) && !ft_strchr(options -> flag, format[i]))
		ft_strlcat(options -> flag, &format[i], ft_strlen(options -> flag) + 2);
	return (options);
}
int		ft_printf_boxing(t_options *options, t_box *box, va_list ap)
{
	
	if (!ft_strchr(TYPE, options -> type) || !options_flag_check(options))
		return (0);
	//value byte and original value assignment
	if (options -> type == 'c' || options -> type == 'd' || options -> type == 'i')
		box -> value = va_arg(ap, int);
	else if(options -> type == 'u' || options -> type == 'x' || options -> type == 'X')
		box -> value = va_arg(ap, unsigned int);
	else if(options -> type == 's' || options -> type == 'p')
		box -> value = va_arg(ap, unsigned long long);
	else if(options -> type == '%')
		box -> value = '%';
	//margin assignment
	//flag assignment
	if (!ft_boxing_flag_n_base(options, box))
		return (0);
	if (!ft_boxing_value_len_n_precision(options, box))
		return (0);
	//precision assignment
	if (!ft_boxing_margin(options, box))
		return (0);
	return (1);
}
