/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:25:40 by dokwak            #+#    #+#             */
/*   Updated: 2021/12/03 18:48:07 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*add_list;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew(f(lst -> content));
	lst = lst -> next;
	while (lst)
	{
		add_list = ft_lstnew(f(lst -> content));
		if (!add_list)
			ft_lstclear(&new_list, del);
		ft_lstadd_back(&new_list, ft_lstnew(f(lst -> content)));
		lst = lst -> next;
	}
	return (new_list);
}
