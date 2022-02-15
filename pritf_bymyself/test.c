#include "test.h"
#include <limits.h>
void	dec_test(void)
{
	int	ft_ret_val;
	int	cr_ret_val;
	/* #######################################################*/
	/* ##################   print decimal   ##################*/
	/* #######################################################*/

	/* test 1 */
	int	a = 12345;
	int	b = -12345;
	int	c = 0;
	int	d = 2147483647;

	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@  correct output  @@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("[TEST 1]\n");
	cr_ret_val = printf("int a = %-10.10d\n", a);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 2 */
	printf("[TEST 2]\n");
	cr_ret_val = printf("int b = %-10.10d\n", b);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 3 */
	printf("[TEST 3]\n");
	cr_ret_val = printf("int c = %10.20d\n", c);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 4 */
	printf("[TEST 4]\n");
	cr_ret_val = printf("int d = %+03.4d\n", d);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 5 */
	printf("[TEST 5]\n");
	cr_ret_val = printf("int e = %012d\n", -2147483647);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n\n");

	/* test 6 */
	printf("[TEST 6]\n");
	cr_ret_val = printf("int f = %02.0d\n", -0);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n\n");

	/* test 7 */
	printf("[TEST 7]\n");
	cr_ret_val = printf("int g = %012d\n", 0);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n\n");

	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@ ft_printf output  @@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	/* test 1 */
	printf("[TEST 1]\n");
	ft_ret_val = ft_printf("int a = %-10.10d\n", a);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 2 */
	printf("[TEST 2]\n");
	ft_ret_val = ft_printf("int b = %-10.10d\n", b);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");
	
	/* test 3 */
	printf("[TEST 3]\n");
	ft_ret_val = ft_printf("int c = %10.20d\n", c);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 4 */
	printf("[TEST 4]\n");
	ft_ret_val = ft_printf("int d = %+03.4d\n", d);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 5 */
	printf("[TEST 5]\n");
	ft_ret_val = ft_printf("int e = %012d\n", -2147483647);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n\n");
	
	/* test 6 */
	printf("[TEST 6]\n");
	ft_ret_val = ft_printf("int f = %02.0d\n", -0);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n\n");

	/* test 7 */
	printf("[TEST 7]\n");
	ft_ret_val = ft_printf("int g = %012d\n", 0);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n\n");
}
void	str_test(void)
{
	int	ft_ret_val;
	int	cr_ret_val;
	/* #######################################################*/
	/* ##################   print string   ###################*/
	/* #######################################################*/
	
	char	*str = "01234567890123456789";
	printf("\t##### expected correct printf output #####\t\n");

	/* test 1 */
	printf("[TEST 1]\n");
	cr_ret_val = printf("cr_printf(-40.10str)=");
	printf("\n");
	printf("cr_ret_val = %d\n", cr_ret_val);
	cr_ret_val = printf("cr_printf(-40.10str)=%-40.10s", str);
	printf("\n");
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");
	
	/* test 2 */
	printf("[TEST 2]\n");
	cr_ret_val = printf("cr_printf(-9.5str)=");
	printf("\n");
	printf("cr_ret_val = %d\n", cr_ret_val);
	cr_ret_val = printf("cr_printf(-9.5str)=%-9.5s", str);
	printf("\n");
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");
	
	/* test 3 */
	printf("[TEST 3]\n");
	cr_ret_val = printf("cr_printf(-5.30str)=");
	printf("\n");
	printf("cr_ret_val = %d\n", cr_ret_val);
	cr_ret_val = printf("cr_printf(-5.30str)=%-5.30s", str);
	printf("\n");
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 4 */
	printf("[TEST 4]\n");
	printf("\n\n");

	/* test 5 */
	printf("[TEST 5]\n");
	printf("\n\n");
	printf("\n\n\n");


	/* ft_printf test */
	printf("\t##### my ft_printf output #####\t\n");

	/* test 1*/
	printf("[TEST 1]\n");
	ft_ret_val = ft_printf("ft_printf(-40.10str)=");
	printf("\n");
	printf("ft_ret_val = %d\n", ft_ret_val);
	ft_ret_val = ft_printf("ft_printf(-40.10str)=%-40.10s", str);
	printf("\n");
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 2 */
	printf("[TEST 2]\n");
	ft_ret_val = ft_printf("ft_printf(-9.5str)=");
	printf("\n");
	printf("ft_ret_val = %d\n", ft_ret_val);
	ft_ret_val = ft_printf("ft_printf(-9.5str)=%-9.5s", str);
	printf("\n");
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");
	
	/* test 3 */
	printf("[TEST 3]\n");
	ft_ret_val = ft_printf("ft_printf(-5.30str)=");
	printf("\n");
	printf("ft_ret_val = %d\n", ft_ret_val);
	ft_ret_val = ft_printf("ft_printf(-5.30str)=%-5.30s", str);
	printf("\n");
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 4 */
	printf("[TEST 4]\n");
	ft_ret_val = ft_printf("%.2s", 0);
	printf("\n");
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");
	
	/* test 5 */
	printf("[TEST 5]\n");
	printf("\n\n");
}
void	usi_test(void)
{
	int	ft_ret_val;
	int	cr_ret_val;
	
	/* test 1 */
	int	ua = 12345;
	int	ub = -12345;
	int	uc = 0;
	int	ud = 2147483647;

	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@  correct output  @@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("[TEST 1]\n");
	cr_ret_val = printf("int ua = %-10.10u\n", ua);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 2 */
	printf("[TEST 2]\n");
	cr_ret_val = printf("int ub = %-10.10u\n", ub);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 3 */
	printf("[TEST 3]\n");
	cr_ret_val = printf("int uc = %10.20u\n", uc);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 4 */
	printf("[TEST 4]\n");
	cr_ret_val = printf("int ud = %03.4u\n", ud);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 5 */
	printf("[TEST 5]\n");
	cr_ret_val = printf("int ue = %3.4u\n", -2147483647);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n\n");

	/* test 6 */
	printf("[TEST 6]\n");
	cr_ret_val = printf("int uf = %02.0u\n", -0);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n\n");

	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@ ft_printf output  @@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	/* test 1 */
	printf("[TEST 1]\n");
	ft_ret_val = ft_printf("int ua = %-10.10u\n", ua);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 2 */
	printf("[TEST 2]\n");
	ft_ret_val = ft_printf("int ub = %-10.10u\n", ub);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");
	
	/* test 3 */
	printf("[TEST 3]\n");
	ft_ret_val = ft_printf("int uc = %10.20u\n", uc);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 4 */
	printf("[TEST 4]\n");
	ft_ret_val = ft_printf("int ud = %03.4u\n", ud);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 5 */
	printf("[TEST 5]\n");
	ft_ret_val = ft_printf("int ue = %3.4u\n", -2147483647);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n\n");
	
	/* test 6 */
	printf("[TEST 6]\n");
	ft_ret_val = ft_printf("int uf = %02.0u\n", -0);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n\n");
}
void	hex_test(void)
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
	cr_ret_val = printf("int xa = %#50.40x\n", xa);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 2 */
	printf("[TEST 2]\n");
	cr_ret_val = printf("int xb = %#050.40x\n", xb);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 3 */
	printf("[TEST 3]\n");
	cr_ret_val = printf("int xc = %#015.40x\n", xc);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 4 */
	printf("[TEST 4]\n");
	cr_ret_val = printf("int xd = %#.40x\n", xd);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");

	/* test 5 */
	printf("[TEST 5]\n");
	cr_ret_val = printf("int -2147483647 = %#.40x\n", -2147483647);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n\n");


	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@ ft_printf output  @@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	/* test 1 */
	printf("[TEST 1]\n");
	ft_ret_val = ft_printf("int xa = %#50.40x\n", xa);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 2 */
	printf("[TEST 2]\n");
	ft_ret_val = ft_printf("int xb = %#050.40x\n", xb);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");
	
	/* test 3 */
	printf("[TEST 3]\n");
	ft_ret_val = ft_printf("int xc = %#015.40x\n", xc);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 4 */
	printf("[TEST 4]\n");
	ft_ret_val = ft_printf("int xd = %#.40x\n", xd);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");

	/* test 5 */
	printf("[TEST 5]\n");
	ft_ret_val = ft_printf("int -2147483647 = %#.40x\n", -2147483647);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n\n");
}
void	char_test(void)
{
	int	ft_ret_val;
	int	cr_ret_val;
	/* #######################################################*/
	/* ####################  print perc  #####################*/
	/* #######################################################*/
	printf("[TEST 1]\n");
	cr_ret_val = printf("%%");
	printf("\n");
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n\n");

	ft_ret_val = ft_printf("%%");
	printf("\n");
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n\n");

	printf("[TEST 2]\n");
	cr_ret_val = printf("%%c%%s%%p%%d%%i%%u%%x%%X%%\n");
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n\n");
	
	ft_ret_val = ft_printf("%%c%%s%%p%%d%%i%%u%%x%%X%%\n");
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n\n");

	printf("[TEST 3]\n");
	cr_ret_val = printf(" 100%% ");
	printf("\n");
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n\n");
	
	ft_ret_val = ft_printf(" 100%% ");
	printf("\n");
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n\n");
	/* #######################################################*/
	/* ####################  print char  #####################*/
	/* #######################################################*/

	char	c_a = 'a';
	char	c_b = '%';
	ft_ret_val = ft_printf("ft_printf(c_a)=%-1c\n", c_a);
	cr_ret_val = printf("cr_printf(c_a)=%-1c\n", c_a);
	ft_ret_val = ft_printf("c_a = %.4c\n", c_a);
	ft_ret_val = ft_printf("c_a = %c\n", c_a);
}
void	pnt_test(void)
{
	int	ft_ret_val;
	int	cr_ret_val;
	/* #######################################################*/
	/* ##################   print pointer   ##################*/
	/* #######################################################*/
	int	pa = 1234;
	char pc = 'c';
	int	arr[3] = {1, 2, 3};
	char	*str = "test";

	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@  correct output  @@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("[TEST 1]\n");
	cr_ret_val = printf("int a's address is %30p\n", &pa);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");
	printf("[TEST 2]\n");
	cr_ret_val = printf("char c's address is %30p\n", &pc);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");
	printf("[TEST 3]\n");
	cr_ret_val = printf("int arr[3]'s address is %6p\n", arr);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");
	printf("[TEST 4]\n");
	cr_ret_val = printf("char *str's address is %p\n", str);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");
	printf("[TEST 5]\n");
	cr_ret_val = printf("-1's address is %p\n", (void *)-1);
	printf("cr_ret_val = %d\n", cr_ret_val);
	printf("\n\n");
	printf("\n\n\n");

	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@ ft_printf output  @@@@@@@@@@@@@@@@@@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

	printf("[TEST 1]\n");
	ft_ret_val = ft_printf("int a's address is %30p\n", &pa);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");
	printf("[TEST 2]\n");
	ft_ret_val = ft_printf("char c's address is %30p\n", &pc);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");
	printf("[TEST 3]\n");
	ft_ret_val = ft_printf("int arr[3]'s address is %p\n", arr);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("\n\n");
	printf("[TEST 4]\n");
	ft_ret_val = ft_printf("char *str's address is %p\n", str);
	printf("ft_ret_val = %d\n", ft_ret_val);
	printf("[TEST 5]\n");
	ft_ret_val = ft_printf("-1's address is %p\n", (void *)-1);
	printf("cr_ret_val = %d\n", ft_ret_val);
	printf("\n\n");
}
