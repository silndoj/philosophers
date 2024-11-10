/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:10:26 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/10 20:00:24 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sit_on_table(char **argv, t_philo *philos)
{
	int	i;
	int	j;

	j = -1;
	i = ft_atoi(argv[1]);
	philos->philo_idx = i;
	philos->philos = ft_malloc(sizeof(*philos) * i);
	while (++j < i)
		philos->philos[j] = (pthread_t) ft_malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
}
