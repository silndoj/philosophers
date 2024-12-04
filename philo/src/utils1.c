/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:17:58 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/27 18:51:59 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	actual_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		ft_exit("Gettimeofday returned -1\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	precise_usleep(long time_in_ms, t_philo *philos)
{
	long	start_time;

	start_time = actual_time();
	while ((actual_time() - start_time) < time_in_ms && philos->flag)
		usleep(100);
}

int	ft_exit(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write (fd, &*s, 1);
		s++;
	}
}
