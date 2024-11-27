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

	i = 0;
	while (philos->flag)
	{
		i = 0;
		while (i < philos->philo_idx)
		{
			if ((actual_time() - philos->p_private[i].last_eat_time)
				> philos->time_to_die)
			{
				philos->flag = 0;
				pthread_mutex_lock(&philos->single_lock);
				printf("%ld %d died\n", actual_time(), \
				philos->p_private[i].idx);
				pthread_mutex_unlock(&philos->single_lock);
				break ;
			}
			i++;
		}
	}
}

void	play_routine(t_philo *philos)
{
	int	i;

	i = -1;
	philos->threads = ft_malloc(sizeof(pthread_t) * philos->philo_idx);
	while (++i < philos->philo_idx)
		pthread_create(&philos->threads[i], NULL, routine,
			&philos->p_private[i]);
	death_cam(philos);
	i = -1;
	while (++i < philos->philo_idx)
		pthread_join(philos->threads[i], NULL);
}
