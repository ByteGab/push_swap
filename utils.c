/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:14:11 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:15:30 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_values(char **argv, int i, int z)
{
	if ((argv[i][z] < '0' || argv[i][z] > '9') && (argv[i][z] != '-'
			&& argv[i][z] != '+'))
	{
		ft_putstr_fd("Error", 1);
		exit(EXIT_FAILURE);
	}
	if ((argv[i][z] == '-' || argv[i][z] == '+') && (argv[i][z + 1] < '0'
			|| argv[i][z + 1] > '9'))
	{
		ft_putstr_fd("Error", 1);
		exit(EXIT_FAILURE);
	}
}

int	count_values(char *argv[], int size)
{
	int	i;
	int	z;
	int	count;

	i = 1;
	count = 0;
	while (i < size)
	{
		z = 0;
		while (argv[i][z] != '\0')
		{
			if (argv[i][z] != ' ')
			{
				check_values(argv, i, z);
				if (argv[i][z + 1] == ' ' || argv[i][z + 1] == '\0')
					count++;
			}
			z++;
		}
		i++;
	}
	return (count);
}
