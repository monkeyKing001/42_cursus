/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:47:55 by dokwak            #+#    #+#             */
/*   Updated: 2022/01/13 17:26:05 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define TYPE "csdiupxX%"

/*
** info structure
*/
typedef struct s_flag
{
	int	flag;
	int	width;
	int	precision;
	int	type;
}							t_flag;
typedef struct s_info
{
	int			left_align;
	int			zero;
	int			width;
	int			prec;
	char		type;
	int			nbr_base;
	int			nbr_sign;
	char		flag;
}	t_info;

/*
**
** printf("%[flag][width][.precision][length]formatspecifier", $(* pnt))
**	char	[flag]
** 		'-' 	: left align. 
**		'0'		: fill left width with '0'.
**		'+' 	: express sign.(bonus part) 
**		' ' 	: do not express flag except minus sign if the case is.(bonus part)
**		'#'		: express base number ex) 0, 0x, 0X.(bonus part)
**	int		[width]
** 	int		[.precision]
**	int		[length]
**	int		[precision]
**	char	[formatspecifier]
** 		%s print a string of characters.
** 		%p The void * pointer argument is printed in hexadecimal. 
**		%d print a decimal (base 10) number.
** 		%i print an integer in base 10.
** 		%u print an unsigned decimal (base 10) number.
** 		%x print a number in hexadecimal (base 16), with lowercase. 
**		%X print a number in hexadecimal (base 16), with uppercase.
**		%% print a percent sign.
*/

/*
** ft_printf 
*/
int		ft_printf(char const *argv, ...);
int		ft_printf_sub(va_list ap, char *format);
int		print_format(va_list ap, t_info *info);
void	check_width_and_prec(va_list ap, char *format, t_info *info, int i);

/*
** ft_printf_char 
*/
int		print_char(int c, t_info *info);
int		put_width(int width, int len, int zero);

/*
** ft_printf_str 
*/
int		print_string(char *str, t_info *info);


/*
** ft_printf_uitils 
*/
t_info	*info_init(t_info *info);

#endif
