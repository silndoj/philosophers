/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:16:38 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/23 16:02:39 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
	{
		printf("Prompt should be as followed\n \
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1)
		return (printf("philos range should be 1-200\n"), 1);
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60
		|| ft_atoi(argv[4]) < 60)
	{
		printf("time_to_die or time_to_eat or time_to_sleep\n");
		printf("should not be less than 60\n");
		return (1);
	}
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
			{
				printf("%s should be INT\n", argv[i]);
				return (1);
			}
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
