#include "libft.h"
#include "stdio.h"

int	main(void)
{
	char	**pnt;
	char	*test = "a....";
	char	del = '.';

	int	i = 0;

	printf("=================== test=====================\n");
	printf("## original string : %s\n", test);
	pnt = ft_split(test, del);
	while (pnt[i])
	{
		printf("chunk num [%d]\n", i);
		printf("splited string : %s\n", pnt[i]);
		i++;
	}
	printf("total splited num : %d\n", i);
	return (0);
}
