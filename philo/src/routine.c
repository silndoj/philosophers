/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:20:18 by silndoj           #+#    #+#             */
/*   Updated: 2024/12/06 21:27:59 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	assign_odd_even(t_private *p_p, t_philo *p)
{
	if (p->philo_idx == 1)
	{
		pthread_mutex_lock(p_p->l_fork);
		pthread_mutex_lock(&p->single_lock);
		printf("%ld philo %d has taken a fork\n", actual_time() \
			- p->start_time, p_p->idx);
		pthread_mutex_unlock(&p->single_lock);
		while (p->flag)
			usleep(100);
		pthread_mutex_unlock(p_p->l_fork);
		return ;
	}
	if (p_p->idx % 2 == 0)
	{
		p_p->f1 = p_p->r_fork;
		p_p->f2 = p_p->l_fork;
	}
	else
	{
		p_p->f1 = p_p->l_fork;
		p_p->f2 = p_p->r_fork;
	}
}

void	p_take_forks(t_philo *philos, t_private *p_private)
{
	assign_odd_even(p_private, philos);
	if (!philos->flag)
		return ;
	pthread_mutex_lock(p_private->f1);
	pthread_mutex_lock(&philos->single_lock);
	printf("%ld philo %d has taken a fork\n", actual_time() \
		- philos->start_time, p_private->idx);
	pthread_mutex_unlock(&philos->single_lock);
	pthread_mutex_lock(p_private->f2);
	if (!philos->flag)
	{
		pthread_mutex_unlock(p_private->f1);
		pthread_mutex_unlock(p_private->f2);
		return ;
	}
	pthread_mutex_lock(&philos->single_lock);
	printf("%ld philo %d has taken a fork\n", actual_time() \
		- philos->start_time, p_private->idx);
	pthread_mutex_unlock(&philos->single_lock);
}

void	p_eat(t_philo *philos, t_private *p_private)
{
	pthread_mutex_lock(&philos->single_lock);
	printf("%ld philo %d is eating\n", actual_time() \
		- philos->start_time, p_private->idx);
	pthread_mutex_unlock(&philos->single_lock);
	precise_usleep(philos->time_to_eat, philos);
	pthread_mutex_lock(&philos->single_lock);
	p_private->last_eat_time = actual_time();
	p_private->meals_eaten++;
	pthread_mutex_unlock(&philos->single_lock);
	pthread_mutex_unlock(p_private->l_fork);
	pthread_mutex_unlock(p_private->r_fork);
}

void	p_sleep(t_philo *philos, t_private *p_private)
{
	pthread_mutex_lock(&philos->single_lock);
	printf("%ld philo %d is sleeping\n", actual_time() \
		- philos->start_time, p_private->idx);
	pthread_mutex_unlock(&philos->single_lock);
	precise_usleep(philos->time_to_sleep, philos);
}

void	*routine(void *arg)
{
	t_private	*p_private;
	t_philo		*philos;

	p_private = (t_private *) arg;
	philos = p_private->philos;
	if (p_private->idx % 2 == 0)
		precise_usleep(philos->time_to_eat / 2, philos);
	while (philos->flag)
	{
		pthread_mutex_lock(&philos->single_lock);
		printf("%ld philo %d is thinking\n", actual_time() \
			- philos->start_time, p_private->idx);
		pthread_mutex_unlock(&philos->single_lock);
		p_take_forks(philos, p_private);
		if (!philos->flag)
			break ;
		p_eat(philos, p_private);
		if (!philos->flag)
			break ;
		p_sleep(philos, p_private);
	}
	return (NULL);
}
