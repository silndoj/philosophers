/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:26:36 by silndoj           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

void	p_take_forks(t_philo *philos, t_private *p_private)
{
	pthread_mutex_lock(p_private->l_fork);
	pthread_mutex_lock(&philos->single_lock);
	printf("%d has taken left fork\n", p_private->idx);
	pthread_mutex_unlock(&philos->single_lock);
	pthread_mutex_lock(p_private->r_fork);
	pthread_mutex_lock(&philos->single_lock);
	printf("%d has taken right fork\n", p_private->idx);
	pthread_mutex_unlock(&philos->single_lock);
}

void	p_eat(t_philo *philos, t_private *p_private)
{
	pthread_mutex_lock(&philos->single_lock);
	printf("%d is eating\n", p_private->idx);
	pthread_mutex_unlock(&philos->single_lock);
	pthread_mutex_unlock(p_private->l_fork);
	pthread_mutex_unlock(p_private->r_fork);
}

void	p_sleep(t_philo *philos, t_private *p_private)
{
	pthread_mutex_lock(&philos->single_lock);
	printf("%d is sleeping\n", p_private->idx);
	pthread_mutex_unlock(&philos->single_lock);
}

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
		p_take_forks(philos, p_private);
		p_eat(philos, p_private);
		p_sleep(philos, p_private);
	}
	return (NULL);
}
