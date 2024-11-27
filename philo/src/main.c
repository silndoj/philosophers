/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:40:12 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/27 19:00:03 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_philo	philos;
	int		i;

	if (init_philos(&philos, argv, argc))
	{
		ft_exit("\nfailed INIT\n");
		free_allocations();
		return (1);
	}
	play_routine(&philos);
	post_clean(&philos);
	return (0);
}
