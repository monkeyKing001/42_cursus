#include "libft.h"
#include "stdio.h"

int	main(void)
{
	char	**pnt;
	char	*test = "abc..d..efg";
	char	del = 0;

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
	printf("strlen : %zu\n", ft_strlen(test));
	return (0);
}
