/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:00:38 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/25 12:29:11 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_sub(const char *format, va_list ap,
		t_options *options, t_box *box)
{
	int			ret_len;
	int			i;

	i = 0;
	ret_len = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			ret_len += write(1, &format[i++], 1);
		if (format[i] == '%')
		{
			options = init_options(options);
			i++;
			while (format[i] != '\0' && !ft_strchr(TYPE, format[i]))
				options = ft_read_options(options, ap, format, i++);
			options -> type = format[i++];
			box = init_box(box);
			if (ft_strchr(TYPE, options->type)
				&& ft_printf_boxing(options, box, ap))
				ret_len += ft_printf_type(options, box);
			else
				ret_len = -1;
		}
	}
	return (ret_len);
}

/*
** until format[i] meets % print string
** until format[i] meets 'TYPE' read options
** after format[i] meets 'TYPE' print arg
** repeat until format[i] meets '\0'
*/

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_box		*box;
	t_options	*options;
	int			ret_len;

	options = malloc(sizeof(t_options));
	if (!options)
		return (-1);
	box = malloc(sizeof(t_box));
	if (!box)
	{
		free(options);
		return (-1);
	}
	va_start(ap, format);
	ret_len = ft_printf_sub(format, ap, options, box);
	free(options);
	free(box);
	va_end(ap);
	return (ret_len);
}
