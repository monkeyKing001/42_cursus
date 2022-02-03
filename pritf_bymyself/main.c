/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:22:27 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/03 15:59:49 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	int	ft_ret_val;
	int	cr_ret_val;

	/* #######################################################*/
	/* ################   print hexadecimal  #################*/
	/* #######################################################*/

	/* test 1 */
	int	xa = 123456789;
	int	xb = -123456789;
	int	xc = 0;
	int	xd = 2147483647;


	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@  correct output  @@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("[TEST 1]\n");
	cr_ret_val = printf("int a = %20x\n", xa);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 2 */
	printf("[TEST 2]\n");
	cr_ret_val = printf("int b = %015x\n", xb);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 3 */
	printf("[TEST 3]\n");
	cr_ret_val = printf("int c = %015x\n", xc);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 4 */
	printf("[TEST 4]\n");
	cr_ret_val = printf("int d = %x\n", xd);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 5 */
	printf("[TEST 5]\n");
	cr_ret_val = printf("int -2147483647 = %x\n", -2147483647);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n\n");


	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@ ft_printf output  @@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	/* test 1 */
	printf("[TEST 1]\n");
	ft_ret_val = ft_printf("int a = %20x\n", xa);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 2 */
	printf("[TEST 2]\n");
	ft_ret_val = ft_printf("int b = %015x\n", xb);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");
	
	/* test 3 */
	printf("[TEST 3]\n");
	ft_ret_val = ft_printf("int c = %015x\n", xc);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 4 */
	printf("[TEST 4]\n");
	ft_ret_val = ft_printf("int d = %x\n", xd);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 5 */
	printf("[TEST 5]\n");
	ft_ret_val = ft_printf("int -2147483647 = %x\n", -2147483647);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n\n");
	long long lla = 3;
	printf("%d\n", (int)lla);
	lla = ~lla;
	printf("%d\n",(int)lla);
	lla++;
	printf("%d\n",(int)lla);
//	char	*xa_s = ft_itoa(xa);
//	char	*xb_s = ft_itoa(xb);
//	char	*xc_s = ft_itoa(xc);
//	char	*xd_s = ft_itoa(xd);
//	printf("xa : %s\n" ,xa_s);
//	printf("xb : %s\n" ,xb_s);
//	printf("xc : %s\n" ,xc_s);
//	printf("xd : %s\n" ,xd_s);
//	printf("////////////////\n");
//	printf("xa : %s\n" ,ft_convert_base(xa_s, "0123456789", "0123456789abcdef"));
//	printf("xb : %s\n" ,ft_convert_base(xb_s, "0123456789", "0123456789abcdef"));
//	printf("xc : %s\n" ,ft_convert_base(xc_s, "0123456789", "0123456789abcdef"));
//	printf("xd : %s\n" ,ft_convert_base(xd_s, "0123456789", "0123456789abcdef"));
//	/* #######################################################*/
//	/* ##################   print decimal   ##################*/
//	/* #######################################################*/
//
//	/* test 1 */
//	int	a = 123456789;
//	int	b = -123456789;
//	int	c = 0;
//	int	d = 2147483647;
//
//	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@  correct output  @@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//	printf("[TEST 1]\n");
//	cr_ret_val = printf("int a = %+20d\n", a);
//	printf("cr_ret_val = %d\n", cr_ret_val);
//	printf("\n\n");
//
//	/* test 2 */
//	printf("[TEST 2]\n");
//	cr_ret_val = printf("int b = %+015d\n", b);
//	printf("cr_ret_val = %d\n", cr_ret_val);
//	printf("\n\n");
//
//	/* test 3 */
//	printf("[TEST 3]\n");
//	cr_ret_val = printf("int c = %+015d\n", c);
//	printf("cr_ret_val = %d\n", cr_ret_val);
//	printf("\n\n");
//
//	/* test 4 */
//	printf("[TEST 4]\n");
//	cr_ret_val = printf("int d = %+d\n", d);
//	printf("cr_ret_val = %d\n", cr_ret_val);
//	printf("\n\n");
//
//	/* test 5 */
//	printf("[TEST 5]\n");
//	cr_ret_val = printf("int c = %+d\n", -2147483647);
//	printf("cr_ret_val = %d\n", cr_ret_val);
//	printf("\n\n\n");
//
//
//	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@ ft_printf output  @@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//	/* test 1 */
//	printf("[TEST 1]\n");
//	ft_ret_val = ft_printf("int a = %+20d\n", a);
//	printf("ft_ret_val = %d\n", ft_ret_val);
//	printf("\n\n");
//
//	/* test 2 */
//	printf("[TEST 2]\n");
//	ft_ret_val = ft_printf("int b = %+015d\n", b);
//	printf("ft_ret_val = %d\n", ft_ret_val);
//	printf("\n\n");
//	
//	/* test 3 */
//	printf("[TEST 3]\n");
//	ft_ret_val = ft_printf("int c = %+015d\n", c);
//	printf("ft_ret_val = %d\n", ft_ret_val);
//	printf("\n\n");
//
//	/* test 4 */
//	printf("[TEST 4]\n");
//	ft_ret_val = ft_printf("int d = %+d\n", d);
//	printf("cr_ret_val = %d\n", ft_ret_val);
//	printf("\n\n");
//
//	/* test 5 */
//	printf("[TEST 5]\n");
//	ft_ret_val = ft_printf("int c = %+d\n", -2147483647);
//	printf("cr_ret_val = %d\n", ft_ret_val);
//	printf("\n\n\n");
	/* #######################################################*/
	/* ####################  print char  #####################*/
	/* #######################################################*/

//	char	c_a = 'a';
//	char	c_b = '%';
//	ft_ret_val = ft_printf("ft_printf(c_a)=%-1c\n", c_a);
//	cr_ret_val = printf("cr_printf(c_a)=%-1c\n", c_a);
//	ret_val = ft_printf("c_a = %.4c\n", c_a);
//	ret_val = ft_printf("c_a = %c\n", c_a);

//	/* #######################################################*/
//	/* ##################   print string   ###################*/
//	/* #######################################################*/
//	
//	char	*str = "01234567890123456789";
//	printf("\t##### expected correct printf output #####\t\n");
//
//	/* test 1 */
//	printf("[TEST 1]\n");
//	cr_ret_val = printf("cr_printf(-40.10str)=");
//	printf("\n");
//	printf("cr_ret_val = %d\n", cr_ret_val);
//	cr_ret_val = printf("cr_printf(-40.10str)=%-40.10s", str);
//	printf("\n");
//	printf("cr_ret_val = %d\n", cr_ret_val);
//	printf("\n\n");
//	
//	/* test 2 */
//	printf("[TEST 2]\n");
//	cr_ret_val = printf("cr_printf(-9.5str)=");
//	printf("\n");
//	printf("cr_ret_val = %d\n", cr_ret_val);
//	cr_ret_val = printf("cr_printf(-9.5str)=%-9.5s", str);
//	printf("\n");
//	printf("cr_ret_val = %d\n", cr_ret_val);
//	printf("\n\n");
//	
//	/* test 3 */
//	printf("[TEST 3]\n");
//	cr_ret_val = printf("cr_printf(-5.30str)=");
//	printf("\n");
//	printf("cr_ret_val = %d\n", cr_ret_val);
//	cr_ret_val = printf("cr_printf(-5.30str)=%-5.30s", str);
//	printf("\n");
//	printf("cr_ret_val = %d\n", cr_ret_val);
//	printf("\n\n");
//
//	/* test 4 */
//	printf("[TEST 4]\n");
//	printf("\n\n");
//
//	/* test 5 */
//	printf("[TEST 5]\n");
//	printf("\n\n");
//	printf("\n\n\n");
//
//
//	/* ft_printf test */
//	printf("\t##### my ft_printf output #####\t\n");
//
//	/* test 1*/
//	printf("[TEST 1]\n");
//	ft_ret_val = ft_printf("ft_printf(-40.10str)=");
//	printf("\n");
//	printf("ft_ret_val = %d\n", ft_ret_val);
//	ft_ret_val = ft_printf("ft_printf(-40.10str)=%-40.10s", str);
//	printf("\n");
//	printf("ft_ret_val = %d\n", ft_ret_val);
//	printf("\n\n");
//
//	/* test 2 */
//	printf("[TEST 2]\n");
//	ft_ret_val = ft_printf("ft_printf(-9.5str)=");
//	printf("\n");
//	printf("ft_ret_val = %d\n", ft_ret_val);
//	ft_ret_val = ft_printf("ft_printf(-9.5str)=%-9.5s", str);
//	printf("\n");
//	printf("ft_ret_val = %d\n", ft_ret_val);
//	printf("\n\n");
//	
//	/* test 3 */
//	printf("[TEST 3]\n");
//	ft_ret_val = ft_printf("ft_printf(-5.30str)=");
//	printf("\n");
//	printf("ft_ret_val = %d\n", ft_ret_val);
//	ft_ret_val = ft_printf("ft_printf(-5.30str)=%-5.30s", str);
//	printf("\n");
//	printf("ft_ret_val = %d\n", ft_ret_val);
//	printf("\n\n");
//
//	/* test 4 */
//	printf("[TEST 4]\n");
//	printf("\n\n");
//	
//	/* test 5 */
//	printf("[TEST 5]\n");
//	printf("\n\n");
	return (0);
}
