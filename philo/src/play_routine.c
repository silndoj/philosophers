/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:54:40 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/23 17:06:58 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	play_routine(t_philo *philos)
{
	int	i;

	i = -1;
	philos->threads = ft_malloc(sizeof(pthread_t) * philos->philo_idx);
	while (++i < philos->philo_idx)
		pthread_create(&philos->threads[i], NULL, routine,
			&philos->p_private[i]);
	i = -1;
	while (++i < philos->philo_idx)
		pthread_join(philos->threads[i], NULL);
}
