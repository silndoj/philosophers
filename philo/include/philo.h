/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:45:36 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/14 20:04:05 by silndoj          ###   ########.fr       */
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
	int				*forks;
}	t_philo;

//Checking
int				philos_checker(t_philo *philos, char **argv);
int				arg_checker(char *argv);

//Initialize
int				sit_on_table(t_philo *philos);
t_philo			*init_philos(char **argv);

//Utils
int				is_digit(char c);
int				ft_atoi(const char *str);


#endif
