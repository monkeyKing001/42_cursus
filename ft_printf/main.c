/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:22:27 by dokwak            #+#    #+#             */
/*   Updated: 2022/01/04 16:39:29 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	print_numbers(int argc, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, argc);
	i = -1;
	printf("ap's address : %p\n", ap);
	printf("argc : %d\n", argc);
	while (++i < argc)
	{
		printf("%d ", va_arg(ap, int));
		printf("ap's address : %p ", ap);
	}
	printf("\n");
	va_end(ap);
}

int	main(int argc, char **argv)
{
	print_numbers(3, 10, 20, 30);
	print_numbers(2, 11, 21);
	print_numbers(3, 12, 22, 32);
	print_numbers(4, 13, 23, 33, 43);
	print_numbers(2, 14, 24);
	return (0);
}
