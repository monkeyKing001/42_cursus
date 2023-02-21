#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
void	ft_put_number(unsigned digit, unsigned length, char *sign, int *g_var);
void	ft_put_digits(long digit, int length, char *sign, int *g_var);

void	ft_put_number(unsigned digits, unsigned length, char *sign, int *g_var)
{
	if (digits >= length)
		ft_put_number(digits / length, length, sign, g_var);
	*g_var += (int)write(1, &sign[digits % length], 1);
}

void	ft_put_digits(long digits, int length, char *sign, int *g_var)
{
	(digits < 0) ? *g_var += (int)write(1, "-", 1), ft_put_number(-digits, length, sign, g_var) : ft_put_number(digits, length, sign, g_var);
}

size_t	ft_put_string(char *string, int length)
{
	while (string && *string && string[length] && ++length);
	return (string ? write(1, string, length) : write(1, "(null)", 6));
}

int	ft_printf(const char *format, ...)
{
	int		g_var = 0;
	va_list	ap;
	va_start(ap, format);
	while (*format)
	{
		//put string
		if (*format == '%' && *(format+1) == 's' && (format += 2))
			g_var += (int)ft_put_string(va_arg(ap, char *), 0);
		//put hexadecimal
		else if (*format == '%' && *(format+1) == 'x' && (format += 2))
			ft_put_number(va_arg(ap, int), 16, "0123456789abcdef", &g_var);
		//put decimal
		else if (*format == '%' && *(format+1) == 'd' && (format += 2))
			ft_put_digits(va_arg(ap, int), 10, "0123456789", &g_var);
		else
			write(1, format++, 1);
	}
	va_end(ap);
	return (g_var);
}

int	main(void)
{
	ft_printf("testing %d\n", 1234);
	ft_printf("testing %x\n", 1234);
	ft_printf("testing %s\n", "1234");
	printf("testing %d\n", 1234);
	printf("testing %x\n", 1234);
	printf("testing %s\n", "1234");
	return (0);
}
