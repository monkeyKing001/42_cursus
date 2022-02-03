/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:22:27 by dokwak            #+#    #+#             */
/*   Updated: 2022/01/13 15:10:53 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	a = 10;
	int	b = -10;
	int	c = 0;
	char	c_a = 'a';
	char	c_b = '%';
	char	*str = "hello another wolrd";
//	ft_printf("hello");
	ft_printf("c_a = %c\n", c_a);
	ft_printf("c_a = %34c\n", c_a);
	ft_printf("c_a = %.4c\n", c_a);
	printf("c_a = %c\n", c_a);
	printf("c_a = %34c\n", c_a);
//	ft_printf("int a = %d\n", a);
//	ft_printf("int b = %d\n", b);
//	ft_printf("int c = %d\n", c);
//	ft_printf("str = %s\n", str);
	return (0);
}
