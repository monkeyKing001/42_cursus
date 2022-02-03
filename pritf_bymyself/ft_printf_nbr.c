/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:48:50 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/01 15:19:38 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_nbr(t_box *box, int nbr)
{
	int		ret_len;
	char	*nbr_str;
	char	*temp_str;

	ret_len = 0;
	nbr_str = ft_itoa(box -> value);
	if (box -> base_len == 16)
	{
		temp_str = nbr_str;
		nbr_str = ft_convert_base(temp_str, "0123456789", box -> base);
		free(temp_str);
	}
	if (box -> sign)
	{
		box -> value_len += 1;	
		if (box -> zero_len)
		{
			write(1, &(box -> sign), 1);
			ret_len += ft_printf_leftmargin_str(box);
		}
		else
		{
			ret_len += ft_printf_leftmargin_str(box);
			write(1, &(box -> sign), 1);
		}
	}
	else
		ret_len += ft_printf_leftmargin_str(box);
	ret_len += write(1, nbr_str, box -> value_len);
	ret_len += ft_printf_rightmargin_str(box);
	//free itoa box
	free(nbr_str);
	return (ret_len);
}
