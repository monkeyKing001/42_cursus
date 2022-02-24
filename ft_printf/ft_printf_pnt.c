/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:37:34 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/24 18:24:55 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
/*
** ###########################
** ####   ft_printf_pnt   ####
** ###########################
** if n == 0, return "0" right away
** if minus, -> restore
** for correct working of itoa_rec
** allocate digit_num + 1 for last '\0'
** fillin the pnt[] from last index(remainder)
** free itoa box
*/
int	ft_printf_pnt(t_box *box)
{
	int		ret_len;
	char	*nbr_str;

	ret_len = 0;
	nbr_str = ull_to_hexbase((unsigned long long)box -> value, box -> base);
	box -> prefix_len = 2;
	box -> value_len = ft_strlen(nbr_str);
	box -> left_margin -= box -> prefix_len;
	box -> right_margin -= box -> prefix_len;
	ret_len += ft_printf_leftmargin_str(box);
	if (box -> prefix_len)
		ret_len += write(1, "0x", 2);
	ret_len += write(1, nbr_str, box -> value_len);
	ret_len += ft_printf_rightmargin_str(box);
	free(nbr_str);
	return (ret_len);
}
