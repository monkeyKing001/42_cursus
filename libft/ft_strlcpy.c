#include <stdio.h>
#include <unistd.h>
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	while (src[i])
		++i;
	return (i);
}

int	main(void)
{
	char	*dest;
	int		dest_len;
	size_t	ret_size;

	dest_len = 15;
	ret_size = ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
	printf("dest : %s\n", dest);
	return (0);
}
