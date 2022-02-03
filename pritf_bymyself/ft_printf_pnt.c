/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:37:34 by dokwak            #+#    #+#             */
/*   Updated: 2022/01/30 14:10:07 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pnt(t_box *box, long long pnt)
{
	int	ret_len;

	ret_len = 0;
	ret_len = pnt;
	ret_len = box -> value;
	return (ret_len);
}
