/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:40:12 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/11 09:10:01 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_philo	*philos;
	int		i;

	if (argc == 2)
	{
		
		philos = ft_malloc(sizeof(t_philo));
		i = sit_on_table(argv, philos);
		printf("return = (%d)\n", i);
	}
	free_allocations();
	return (0);
}
