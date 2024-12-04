/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:20:18 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/27 18:51:42 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

void	p_take_forks(t_philo *philos, t_private *p_private)
{
	pthread_mutex_t *first_fork;
	pthread_mutex_t *second_fork;

	if (philos->philo_idx == 1)
	{
		pthread_mutex_lock(p_private->l_fork);
		pthread_mutex_lock(&philos->single_lock);
		printf("%ld %d has taken a fork\n", actual_time() - philos->start_time, p_private->idx);
		pthread_mutex_unlock(&philos->single_lock);
		while (philos->flag)
			usleep(100);
		pthread_mutex_unlock(p_private->l_fork);
		return;
	}

	if (p_private->idx % 2 == 0)
	{
		first_fork = p_private->r_fork;
		second_fork = p_private->l_fork;
	}
	else
	{
		first_fork = p_private->l_fork;
		second_fork = p_private->r_fork;
	}
	pthread_mutex_lock(first_fork);
	pthread_mutex_lock(&philos->single_lock);
	printf("%ld %d has taken a fork\n", actual_time() - philos->start_time, p_private->idx);
	pthread_mutex_unlock(&philos->single_lock);
	pthread_mutex_lock(second_fork);
	pthread_mutex_lock(&philos->single_lock);
	printf("%ld %d has taken a fork\n", actual_time() - philos->start_time, p_private->idx);
	pthread_mutex_unlock(&philos->single_lock);
}

void	p_eat(t_philo *philos, t_private *p_private)
{
	pthread_mutex_lock(&philos->single_lock);
	p_private->last_eat_time = actual_time();
	printf("%ld %d is eating\n", actual_time() - philos->start_time, p_private->idx);
	pthread_mutex_unlock(&philos->single_lock);
	
	precise_usleep(philos->time_to_eat);
	
	pthread_mutex_lock(&philos->single_lock);
	p_private->meals_eaten++;
	pthread_mutex_unlock(&philos->single_lock);
	
	pthread_mutex_unlock(p_private->l_fork);
	pthread_mutex_unlock(p_private->r_fork);
}

void	p_sleep(t_philo *philos, t_private *p_private)
{
	pthread_mutex_lock(&philos->single_lock);
	printf("%ld %d is sleeping\n", actual_time() - philos->start_time, p_private->idx);
	pthread_mutex_unlock(&philos->single_lock);
	precise_usleep(philos->time_to_sleep);
}

void	*routine(void *arg)
{
	t_private	*p_private;
	t_philo		*philos;

	p_private = (t_private *) arg;
	philos = p_private->philos;
	
	if (p_private->idx % 2 == 0)
		precise_usleep(philos->time_to_eat / 2);
		
	while (philos->flag)
	{
		pthread_mutex_lock(&philos->single_lock);
		printf("%ld %d is thinking\n", actual_time() - philos->start_time, p_private->idx);
		pthread_mutex_unlock(&philos->single_lock);
		
		p_take_forks(philos, p_private);
		p_eat(philos, p_private);
		p_sleep(philos, p_private);
	}
	return (NULL);
}
