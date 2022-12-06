/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:33:06 by hwichoi           #+#    #+#             */
/*   Updated: 2022/12/06 21:17:51 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_exit(t_desk *desk)
{
	int	i;
	int	full_cnt;

	i = 0;
	full_cnt = 0;
	while (i < desk -> phils_num)
	{
		if (check_full(desk, i) == 1)
			full_cnt++;
		check_die(desk, i);
		i++;
	}
	if (check_die_desk(desk, 0, CHECK) == 1)
		return (1);
	if (full_cnt++ == desk -> phils_num)
		return (1);
	return (0);
}

int	single_phil_case(t_desk *desk)
{
	print_state(desk, 0, FORK);
	time_passing(desk -> time_to_die);
	print_state(desk, 0, DIED);
	pthread_mutex_destroy(&desk -> forks[0]);
	free(desk -> phils);
	pthread_mutex_destroy(&desk -> desk_die_mutex);
	pthread_mutex_destroy(&desk -> print_mutex);
	return (1);
}
