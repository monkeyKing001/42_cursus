/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:37:34 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/14 18:55:04 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** if n == 0, return "0" right away
** for correct working of itoa_rec
** allocate digit_num + 1 for last '\0'
** fillin the pnt[] from last index(remainder)
*/
int		ft_printf_pnt(t_box *box)
{
	int		ret_len;
	char	*nbr_str;

	ret_len = 0;
	//if minus, -> restore
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
	//free itoa box
	free(nbr_str);
	return (ret_len);
}

/*
** div n first to prevent the overflow
** while condition checks if n is 0 or not  
** so, if n is 0, we can not get right digit_num.
*/

char	*ull_to_hexbase(unsigned long long nbr, char *base_to)
{
	int					malloc_size;
	int					i;
	char				*ret_str;
	unsigned long long	temp_nbr;

	malloc_size = get_malloc_size(nbr, base_to);
	ret_str = (char *)malloc(sizeof(char) * malloc_size + 1);
	ret_str[malloc_size] = '\0';
	temp_nbr = nbr;
	i = malloc_size - 1;
	while (malloc_size-- > 0)
	{
		ret_str[i--] = base_to[temp_nbr % ft_strlen(base_to)];
		temp_nbr /= ft_strlen(base_to);
	}
	return (ret_str);
}
