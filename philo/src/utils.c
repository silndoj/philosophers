/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:16:38 by silndoj           #+#    #+#             */
/*   Updated: 2024/12/03 19:26:46 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdlib.h>

void	post_clean(t_philo *philos)
{
	int	i;

	i = -1;
	if (!philos)
		return ;
	if (philos->forks)
	{
		while (++i < philos->philo_idx)
			pthread_mutex_destroy(&philos->forks[i]);
		pthread_mutex_destroy(&philos->single_lock);
	}
	free_allocations();
}

int	is_digit(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else if ((int)c >= 48 && (int)c <= 57)
		return (1);
	return (0);
}

int	philos_checker(t_philo *philos, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (ft_exit("Prompt should be as followed\n \
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n"));
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1)
		return (ft_exit("philos range should be 1-200\n"));
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60
		|| ft_atoi(argv[4]) < 60)
		return (ft_exit("time_to_die or time_to_eat or time_to_sleep \
should not be less than 60\n"));
	return (0);
}

int	arg_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!is_digit(argv[i][j]))
				return (ft_exit("one of Arg is not an INT\n"));
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		n;
	int		result;

	n = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	else if (str[i] == '-')
	{
		n *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * n);
}
