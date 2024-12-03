/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:40:12 by silndoj           #+#    #+#             */
/*   Updated: 2024/12/03 12:45:32 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_philo	philos;

	if (init_philos(&philos, argv, argc))
	{
		post_clean(&philos);
		return (ft_exit("\nFailed INIT\n"));
	}
	play_routine(&philos);
	post_clean(&philos);
	return (0);
}
