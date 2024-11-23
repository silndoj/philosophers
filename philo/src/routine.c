/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:26:36 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/23 17:13:13 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

void	*routine(void *arg)
{
	t_private	*p_private;
	t_philo		*philos;

	p_private = (t_private *) arg;
	philos = p_private->philos;
	while (philos->flag)
	{
		pthread_mutex_lock(&philos->single_lock);
		printf("%d is thinking\n", p_private->idx);
		pthread_mutex_unlock(&philos->single_lock);
//		if (p_private->idx + 1 > p_private->idx)
//			philos->flag = 0;
	}
	return (NULL);
}
