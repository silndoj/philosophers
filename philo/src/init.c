/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:10:26 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/12 16:02:43 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

int	sit_on_table(char **argv, t_philo *philos)
{
	int	i;
	int	j;

	j = -1;
	i = ft_atoi(argv[1]);
	philos->philo_idx = i;
	philos->philos = ft_malloc(sizeof(pthread_t) * i);
	pthread_mutex_init(&philos->mutex, NULL);
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
