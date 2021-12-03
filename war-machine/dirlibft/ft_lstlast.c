/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:29:14 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/03 14:31:12 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*pnt;

	if (lst == NULL)
		return (NULL);
	pnt = lst;
	while (pnt -> next)
		pnt = pnt -> next;
	return (pnt);
}
