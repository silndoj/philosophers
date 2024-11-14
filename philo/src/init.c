/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:10:26 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/14 20:20:46 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>
#include <stdlib.h>

int mails = 0;

void* routine(void* arg)
{
	int	i;
	char	*ptr;

	i = -1;
    while (++i < 1000000) {
        pthread_mutex_lock(arg);
        mails++;
        pthread_mutex_unlock(arg);
    }
	return ((void*) ptr);
}

int philos_checker(t_philo *philos, char **argv)
{
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1)
	{
		printf("philos range should be 1-200\n");
		return (1);
	}
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60
	|| ft_atoi(argv[4]) < 60)
	{
		printf("time_to_die or time_to_eat or time_to_sleep\n");
		printf("should not be less than 60\n");
		return (1);
	}
	philos->philo_idx = ft_atoi(argv[1]);
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
	return (0);
}

t_philo	*init_philos(char **argv)
{
	t_philo	*philos;

	philos = ft_malloc(sizeof(t_philo));
	if (arg_checker(argv[1]) || arg_checker(argv[2])
	|| arg_checker(argv[3]) || arg_checker(argv[4]))
		return (NULL);
	if (philos_checker(philos, argv))
		return (NULL);
	philos->forks = ft_malloc(sizeof(int) * philos->philo_idx);
	philos->philos = ft_malloc(sizeof(pthread_t) * philos->philo_idx);
	pthread_mutex_init(&philos->mutex, NULL);
	printf("address of struct = %p\n", philos);
	printf("success initialization!!\n");
	return (philos);
}

int	sit_on_table(t_philo *philos)
{
	int	i;
	int	j;

	j = -1;
	i = philos->philo_idx;
    while (++j < i)
	{
		if (pthread_create(philos->philos + j, NULL, &routine, &philos->mutex) != 0)
		{
			perror("Failed to create thread");
            return 1;
        }
        printf("Thread %d has started\n", j);
    }
	j = -1;
    while (++j < i)
	{
		if (pthread_join(philos->philos[j], NULL) != 0)
			return 2;
        printf("Thread %d has finished execution\n", j);
    }
    pthread_mutex_destroy(&philos->mutex);
    printf("Number of mails: %d\n", mails);
    return 0;
}
