/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:46:55 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/02 17:55:51 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
long long	count_chnk_num(char const *s, char c)
{
	long long	chnk_num;
	char const	*s_pnt1;

	s_pnt1 = s;
	chnk_num = 0;
	while (s)
	{
		s_pnt1 = ft_strchr(s, c);
		if (s_pnt1 != s)
			chnk_num++;
		s = s_pnt1 + 1;
	}
	return (chnk_num);
}

char	**ft_split(char const *s, char c)
{
	long long	chnk_num;
	long long	i;
	char const	*s_pnt1;
	char		**ret_pnt;

	chnk_num = count_chnk_num(s, c);
	ret_pnt = malloc(sizeof(char *) * (chnk_num + 1));
	if (chnk_num == 0 || ret_pnt == 0)
		return (NULL);
	s_pnt1 = s;
	i = 0;
	while (s)
	{
		s_pnt1 = ft_strchr(s, c);
		if (s_pnt1 != s)
		{
			if (s_pnt1)
				s_pnt1 = 0;
			ret_pnt[i++] = ft_substr(s, 0, ft_strlen((char *)s));
		}
		s = s_pnt1 + 1;
	}
	ret_pnt[i] = NULL;
	return (ret_pnt);
}
