#include <stdio.h>
#include "libft.h"
int		get_digit_num(int n);
void	itoa_rec(int n, int index, char *pnt);
char	*ft_itoa(int n);

int	main(void)
{
	char	*str;
	int		num;

	num = -1;
	str = ft_itoa(num);
	printf("num : %d\n", num);
	printf("digit_num : %d\n", get_digit_num(num));
	printf("%s\n", str);
	return (0);
}
