/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:01:26 by dokwak            #+#    #+#             */
/*   Updated: 2022/02/14 19:46:42 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h> //delete before submission
# include "./libft/libft.h"

# define TYPE "csdiupxX%"
# define FLAG "0-*+# "
# define NULL_STR "(null)"
/*
**
** printf("%[flag][width][.precision][length]formatspecifier", $(* pnt))
**	char	[flag]
** 		'-' 	: left align. 
**		'0'		: fill left width with '0'.
**		'+' 	: express sign.(bonus part) 
**		' ' 	: do not express options except minus sign if the case is.(bonus part)
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

typedef struct s_options
{
	char flag[7];
	int	width;
	int	precision;
	int	type;
}	t_options;

typedef struct	s_box
{
	int						left_margin; //왼쪽 스페이스 개수
	int						right_margin; //오른쪽 스페이스 개수
	char					sign; // - 출력
	int						zero_len; //출력할 0의 개수
	int 					prefix_len; //0x 출력 여부 (0 or 2)
	long long     			value; //va_arg 값
	int						value_len; //va_arg 값의 길이
	char					base[20]; //진수
	int						base_len; //진수
	int						precision;
}	t_box;

/*
 ** ft_printf
 */

int			ft_printf(const char *format, ...);
int			ft_printf_sub(const char *format, va_list ap, t_options *options, t_box *box);

/*
 ** ft_printf_preprocess
 */

t_options	*ft_read_ap(t_options *options, va_list ap);
t_options	*ft_read_options(t_options *options, va_list ap, const char *format, int i);
int		ft_printf_boxing(t_options *options, t_box *box, va_list ap);

/*
 ** ft_printf_utils
 */

t_options	*init_options(t_options	*options);
t_box		*init_box(t_box *box);
int			options_flag_check(t_options *options);

/*
 ** ft_printf_utils2
 */
char			*dec_to_base(unsigned int nbr, char *base_to);
unsigned int	ft_str_to_dec(char *nbr, char *base_from);
int				get_index(char *base, char chr);
int				get_malloc_size(unsigned long long dec, char *base_to);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);

/*
** ft_printf_boxing
*/
int		ft_boxing_value_len_n_precision(t_options *options, t_box *box);
int		ft_boxing_margin(t_options *options, t_box *box);
int		ft_boxing_precision(t_options *options, t_box *box);
int		ft_boxing_flag_n_base(t_options *options, t_box *box);

/*
** ft_printf_printphase
*/

int		ft_printf_type(t_options *options, t_box *box);

/*
** ft_printf_char
*/
int		ft_printf_leftmargin(t_box *box);
int 	ft_printf_rightmargin(t_box *box);
int		ft_printf_char(t_box *box);

/*
** ft_printf_string
*/
int		ft_printf_leftmargin_str(t_box *box);
int		ft_printf_rightmargin_str(t_box *box);
int		ft_printf_str(t_box *box);

/*
** ft_printf_pnt
*/
int		ft_printf_pnt(t_box *box);
char	*ull_to_hexbase(unsigned long long nbr, char *base_to);

/*
** ft_printf_nbr
*/
int		ft_printf_nbr(t_box *box);
int		ft_printf_leftmargin_nbr(t_box *box);
int		ft_printf_rightmargin_nbr(t_box *box);

/*
** ft_printf_unsigned
*/
int		ft_printf_unsigned(t_box *box);
char	*ft_uitoa(unsigned int n);
/*
** ft_uitoa
**/
#endif
