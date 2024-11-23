/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:40:12 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/23 17:02:20 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_philo	philos;
	int		i;

	if (init_philos(&philos, argv, argc))
	{
		printf("\nfailed INIT\n");
		free_allocations();
		return (1);
	}
	post_clean(&philos);
	return (0);
}
