#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int	main(void)
{
	char n[20] = "123";
	char *s = "abcdefg";
	
	printf("n[%zu] = %s\n", sizeof(n), n);
	printf("s[%zu] = %s\n", sizeof(s), s);
	printf("\n=======after strlcat =====\n\n");
	size_t lcat_ret = strlcat(n, (const char *) s, 11);
	if (!strcmp(n, "123abcdefg"))
		printf("strlcat succeeded!\n");
	else if(strcmp(n, "123"))
		printf("strlcat partially succeeded!\n");
	else
		printf("strlcat failed!\n");
	printf("n[%zu] = %s\n", sizeof(n), n);
	printf("return val = %zu\n", lcat_ret);
	return (0);
}
