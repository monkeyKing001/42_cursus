/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:20:54 by dokwak            #+#    #+#             */
/*   Updated: 2022/01/13 17:18:11 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_format(va_list ap, t_info *info)
{
	int				ret;
	char			type;

	ret = 0;
	type = info->type;
	if (type == 'c')
		ret = print_char(va_arg(ap, int), info);
	else if (type == 's')
		ret = print_string(va_arg(ap, char *), info);
	return (ret);
}
//	else if (type == '%')
//		ret = print_char('%', info);
//	else if (type == 'd' || type == 'i')
//		ret = print_nbr(va_arg(ap, int), info);
//	else if (type == 'x' || type == 'X' || type == 'u')
//		ret = print_nbr(va_arg(ap, unsigned int), info);
//	else if (type == 'p')
//		ret = print_nbr(va_arg(ap, unsigned long long), info);

void	check_width_and_prec(va_list ap,
		char *format, t_info *info, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + format[i] - 48;
		else
			info->prec = info->prec * 10 + format[i] - 48;
	}
	else if (format[i] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->left_align = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(ap, int);
	}
}

t_info	*parse_info(t_info *info, va_list ap, char *format, int i)
{
	if (format[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (format[i] == '-')
		info->left_align = 1;
	else if (format[i] == '.')
		info->prec = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		check_width_and_prec(ap, format, info, i);
	return (info);
}

int	ft_printf_sub(va_list ap, char *format)
{
	int		output_len;
	int		i;
	t_info	*info;

	info = malloc(sizeof(t_info) * 1);
	if (!info)
		return (0);
	output_len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '\0' && format[i] != '%')
			output_len += write(1, &format[i++], 1);
		if (format[i] == '%')
		{
			info = info_init(info);
			//parse_info should deal with the format until it meets format specifier
			//parsing format info and what if unvalid formating? ex) %\0
			while (format[++i] != '\0' && !ft_strchr(TYPE, format[i]))
				info = parse_info(info, ap, format, i);
			info->type = format[i++];
			//belows are for what?
			if ((info->left_align == 1 || info->prec > -1) && info->type != '%')
				info->zero = 0;
			output_len += print_format(ap, info);
		}
	}
	free(info);
	return (output_len);
}
/*
** be cautious that parse_info returns (t_info *)
** what if type format is not adquate (ex. %(null))
*
*/

int	ft_printf(char const *format, ...)
{
	int		output_len;
	va_list	ap;

	va_start(ap, format);
	output_len = ft_printf_sub(ap, (char *)format);
	va_end(ap);
	return (output_len);
}
/*
** va(Vriable Argument) can be accessed by va_list type pointer(ap)
** ap can be moved with va_arg(ap, TYPE)function by sizeof(TYPE)
** you should deal with
** printf("%[flag][width][.precision][length]formatspecifier", $(* pnt))
**
*/
