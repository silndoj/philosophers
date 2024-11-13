/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:40:12 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/13 17:14:32 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_philo	*philos;
	int		i;

	if (argc == 5)
	{
		philos = init_philos(argv);
		printf("address of struct = %p\n", philos);
		i = sit_on_table(philos);
		printf("return = (%d)\n", i);
	}
	free_allocations();
	return (0);
}
