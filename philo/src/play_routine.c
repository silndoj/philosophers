/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:54:40 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/27 19:00:39 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	death_cam(t_philo *philos)
{
	int	i;
	int all_ate_enough;

	i = 0;
	while (philos->flag)
	{
		i = 0;
		all_ate_enough = 1;
		while (i < philos->philo_idx)
		{
			pthread_mutex_lock(&philos->single_lock);
			if ((actual_time() - philos->p_private[i].last_eat_time)
				> philos->time_to_die)
			{
				philos->flag = 0;
				printf("%ld %d died\n", actual_time() - philos->start_time,
					philos->p_private[i].idx);
				pthread_mutex_unlock(&philos->single_lock);
				return ;
			}
			pthread_mutex_unlock(&philos->single_lock);
			i++;
		}
		usleep(100);
	}
}

void	play_routine(t_philo *philos)
{
	int	i;

	philos->start_time = actual_time();
	i = -1;
	while (++i < philos->philo_idx)
		philos->p_private[i].last_eat_time = philos->start_time;
		
	i = -1;
	while (++i < philos->philo_idx)
		pthread_create(&philos->threads[i], NULL, routine,
			&philos->p_private[i]);
			
	death_cam(philos);
	
	i = -1;
	while (++i < philos->philo_idx)
		pthread_join(philos->threads[i], NULL);
}
