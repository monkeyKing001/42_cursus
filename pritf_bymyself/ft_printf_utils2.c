/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:33:19 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/08 01:21:03 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	get_malloc_size(unsigned long long dec, char *base_to)
{
	int					to_base_len;
	int					len_for_malloc;
	unsigned long long	temp;

	temp = dec;
	to_base_len = ft_strlen(base_to);
	len_for_malloc = 0;
	while (temp >= 0)
	{
		len_for_malloc++;
		temp /= to_base_len;
		if (temp == 0)
			break ;
	}
	return (len_for_malloc);
}

unsigned int	ft_str_to_dec(char *nbr, char *base_from)
{
	unsigned int	ret;
	int				neg_pos;

	neg_pos = 1;
	ret = 0;
	while (get_index(base_from, *nbr) > -1)
	{
		ret = ret * ft_strlen(base_from)
			+ get_index(base_from, *nbr) * neg_pos;
		nbr++;
	}
	return (ret);
}

char	*dec_to_base(unsigned int nbr, char *base_to)
{
	int				malloc_size;
	int				i;
	char			*ret_str;
	unsigned int	temp_nbr;

	malloc_size = get_malloc_size(nbr, base_to);
	ret_str = (char *)malloc(sizeof(char) * malloc_size + 1);
	ret_str[malloc_size] = '\0';
	temp_nbr = nbr;
	i = 0;
	i += malloc_size - 1;
	while (malloc_size-- > 0)
	{
		ret_str[i--] = base_to[temp_nbr % ft_strlen(base_to)];
		temp_nbr /= ft_strlen(base_to);
	}
	return (ret_str);
}

int	get_index(char *base, char chr)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(base))
	{
		if (base[i] == chr)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*str_to_base;
	unsigned int	dec;

	dec = ft_str_to_dec(nbr, base_from);
	str_to_base = dec_to_base(dec, base_to);
	return (str_to_base);
}
