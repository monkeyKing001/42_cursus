/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_preprocess.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:03:53 by dokwak            #+#    #+#             */
/*   Updated: 2022/01/31 16:42:01 by dokwak           ###   ########.fr       */
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
