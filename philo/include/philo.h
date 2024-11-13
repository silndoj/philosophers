/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:45:36 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/13 17:12:56 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include "garbage_collector.h"

typedef struct	philo_t
{
	pthread_mutex_t	mutex;
	pthread_t		*philos;
	int				philo_idx;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
}	t_philo;

//Initialize
int				sit_on_table(t_philo *philos);
int				ft_atoi(const char *str);
t_philo			*init_philos(char **argv);

#endif
