/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:45:36 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/23 14:23:08 by silndoj          ###   ########.fr       */
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
	int				philo_idx;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
}	t_philo;

//Initialize
int				sit_on_table(t_philo *philos);
int				init_philos(t_philo *philos, char **argv, int argc);

//Utils
int				is_digit(char c);
int				ft_atoi(const char *str);
int				philos_checker(t_philo *philos, int argc, char **argv);
int				arg_checker(char **argv);

#endif
