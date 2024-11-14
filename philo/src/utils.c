/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:16:38 by silndoj           #+#    #+#             */
/*   Updated: 2024/11/14 20:20:18 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>

int	is_digit(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else if ((int)c >= 48 && (int)c <= 57)
		return (1);
	return (0);
}

int arg_checker(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!is_digit(argv[i]))
		{
			printf("please add correctly arguments\n");
			return (1);
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
