/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:23:55 by dokwak            #+#    #+#             */
/*   Updated: 2022/01/12 16:30:44 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
t_info	*info_init(t_info *info)
{
	info -> left_align = 0;
	info -> zero = 0;
	info -> width = 0;
	info -> prec = -1;
	info -> type = 0;
	info -> nbr_base = 10;
	info -> nbr_sign = 1;
	return (info);
}

