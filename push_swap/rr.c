/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:43:25 by dokwak            #+#    #+#             */
/*   Updated: 2022/07/08 18:43:55 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_ra(t_info *info)
{
	t_num	*tmp;

	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->top_a->prev = NULL;
	info->bot_a->next = tmp;
	tmp->prev = info->bot_a;
	info->bot_a = tmp;
	info->bot_a->next = NULL;
}

void	ra(t_info *info)
{
	if (info->size_a < 2)
		return ;
	ft_ra(info);
	write(1, "ra\n", 3);
}

void	ft_rb(t_info *info)
{
	t_num	*tmp;

	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->top_b->prev = NULL;
	info->bot_b->next = tmp;
	tmp->prev = info->bot_b;
	info->bot_b = tmp;
	info->bot_b->next = NULL;
}

void	rb(t_info *info)
{
	if (info->size_b < 2)
		return ;
	ft_rb(info);
	write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	if (info->size_a < 2 || info->size_b < 2)
		return ;
	ft_ra(info);
	ft_rb(info);
	write(1, "rr\n", 3);
}
