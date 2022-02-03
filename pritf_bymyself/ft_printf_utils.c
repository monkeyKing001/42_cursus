/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:40:54 by dokwak            #+#    #+#             */
/*   Updated: 2022/01/31 16:47:10 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_options	*init_options(t_options	*options)
{
	options -> flag[0] = 0;
	options -> left_align = 0;
	options -> width = 0;
	options -> precision = -1;
	options -> type = 0;
	return (options);
}

t_box	*init_box(t_box *box)
{
	box -> left_margin = 0; //왼쪽 스페이스 개수
	box -> right_margin = 0; //오른쪽 스페이스 개수
	box -> sign = 0; // - 출력
	box -> zero_len = 0; //출력할 0의 개수
	box -> prefix_len = 0; //0x 출력 여부 (0 or 2)
	box -> value = 0; //va_arg 값
	box -> value_len = 0; //va_arg 값의 길이
	box -> base_len = (int)ft_strlcpy(box -> base, "0123456789", 11); //진수
	return (box);
}

int		options_flag_check(t_options *options)
{
	int	i;

	i = -1;
	while (options -> flag[++i])
		if (!ft_strchr(FLAG, options -> flag[i]))
			return (0);
	return (1);
}
