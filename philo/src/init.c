/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:10:26 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/28 13:58:34 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_forks(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->philo_idx)
		pthread_mutex_init(&philos->forks[i], NULL);
	pthread_mutex_init(&philos->single_lock, NULL);
}

void	init_single_philo(t_philo *philos)
{
	int	i;
	int	idx;

	i = -1;
	idx = philos->philo_idx;
	while (++i < idx)
	{
		philos->p_private[i].idx = i + 1;
		philos->p_private[i].meals_eaten = 0;
		philos->p_private[i].last_eat_time = actual_time();
		philos->p_private[i].l_fork = &philos->forks[i];
		philos->p_private[i].r_fork = &philos->forks[(i + 1) % idx];
		philos->p_private[i].philos = philos;
	}
}

int	philos_init(t_philo *philos, int argc, char **argv)
{
	if (!philos_checker(philos, argc, argv))
	{
		philos->philo_idx = ft_atoi(argv[1]);
		philos->time_to_die = ft_atoi(argv[2]);
		philos->time_to_eat = ft_atoi(argv[3]);
		philos->time_to_sleep = ft_atoi(argv[4]);
		philos->flag = 1;
		if (argc == 6)
			philos->number_of_meals = ft_atoi(argv[5]);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	init_philos(t_philo *philos, char **argv, int argc)
{
	if (arg_checker(argv))
		return (EXIT_FAILURE);
	if (philos_init(philos, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philos->forks = ft_malloc(sizeof(pthread_mutex_t) * philos->philo_idx);
	philos->p_private = ft_malloc(sizeof(t_private) * philos->philo_idx);
	if (!philos->forks || !philos->p_private)
		return (ft_exit("Memory Alloc Failed\n"));
	init_forks(philos);
	init_single_philo(philos);
	return (0);
}
