/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:46:55 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/09 16:42:42 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
static char	**free_all(char **ret_pnt)
{
	long long	i;

	i = 0;
	if (ret_pnt == NULL)
		return (NULL);
	while (ret_pnt[i])
	{
		free(ret_pnt[i]);
		i++;
	}
	free(ret_pnt);
	return (NULL);
}

static long long	count_chnk_num(char const *s, char c)
{
	long long	chnk_num;
	char const	*s_pnt1;

	s_pnt1 = s;
	chnk_num = 0;
	while (*s)
	{
		s_pnt1 = ft_strchr(s, c);
		if (s_pnt1 != s)
			chnk_num++;
		if (!s_pnt1)
			break ;
		s = s_pnt1 + 1;
	}
	return (chnk_num);
}
/*
** if fail to allocating memory free every memory allocated before 
** s = abcde.fghij..klm,  c = '.' 								  
**     o    v										
**           o    v   										
**                 o   										
**				   	o											
** s = o, s_pnt1 = v 											
*/

static char	**ft_sub_split(char **ret_pnt, char const *s, char c)
{
	long long	i;
	char const	*s_pnt1;

	i = 0;
	while (*s)
	{
		s_pnt1 = ft_strchr(s, c);
		if (s_pnt1 == NULL || s_pnt1 != s)
		{
			if (s_pnt1 == NULL)
				ret_pnt[i] = ft_substr(s, 0, ft_strlen((char *)s));
			else if (s_pnt1 != s)
				ret_pnt[i] = ft_substr(s, 0, s_pnt1 - s);
			if (ret_pnt[i] == NULL)
				return (free_all(ret_pnt));
			i++;
		}
		if (s_pnt1 == NULL)
			break ;
		if (*s_pnt1 == 0)
			break ;
		s = s_pnt1 + 1;
	}
	ret_pnt[i] = NULL;
	return (ret_pnt);
}

char	**ft_split(char const *s, char c)
{
	char		**ret_pnt;

	if (!s)
		return (NULL);
	ret_pnt = malloc(sizeof(char *) * (count_chnk_num(s, c) + 1));
	if (ret_pnt == NULL)
		return (NULL);
	ret_pnt = ft_sub_split(ret_pnt, s, c);
	return (ret_pnt);
}
/*
** s_pnt1 == NULL -> last word
** s_pnt1 == address -> delimeter point
** don't forget the last NULL pointer
*/
