/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:58:26 by dokwak            #+#    #+#             */
/*   Updated: 2022/01/12 17:07:34 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_width(int width, int len, int zero)
{
	int		ret;

	ret = 0;
	while (len < width)
	{
		if (zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		len++;
		ret++;
	}
	return (ret);
}

int	print_char(int c, t_info *info)
{
	int		ret;

	ret = 0;
	if (info->type == '%' && info->left_align == 1)
		info->zero = 0;
	if (info->left_align == 1)
		ret += write(1, &c, 1);
	ret += put_width(info->width, 1, info->zero);
	if (info->left_align == 0)
		ret += write(1, &c, 1);
	return (ret);
}
