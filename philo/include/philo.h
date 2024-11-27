/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:45:36 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/27 19:00:11 by silndoj          ###   ########.fr       */
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

typedef struct private_t
{
	int				idx;
	int				meals_eaten;
	long			last_eat_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct philo_t	*philos;
}	t_private;

typedef struct philo_t
{
	int				flag;
	int				philo_idx;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	single_lock;
	t_private		*p_private;
}	t_philo;

//Initialize
int				init_philos(t_philo *philos, char **argv, int argc);
int				philos_init(t_philo *philos, int argc, char **argv);
void			init_single_philo(t_philo *philos);
void			init_forks(t_philo *philos);

//Routine_+_Simulation
void			*routine(void *arg);
void			play_routine(t_philo *philos);

//Utils
void			post_clean(t_philo *philos);
int				is_digit(char c);
int				ft_atoi(const char *str);
int				arg_checker(char **argv);
int				philos_checker(t_philo *philos, int argc, char **argv);

//Utils1
long int		actual_time(void);
void			precise_usleep(long time_in_ms);
int				ft_exit(char *str);
void			ft_putstr_fd(char *s, int fd);

#endif
