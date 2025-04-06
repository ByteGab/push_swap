/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:14:11 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/07 01:46:31 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_valors(char *argv[], int size)
{
	int	i;
	int	z;
	int	count;

	i = 1;
	count = 0;
	while (i < size)
	{
		z = 0;
		printf("%s ", argv[i]);
		while (argv[i][z] != '\0')
		{
			if (argv[i][z] != ' ')
			{
				// Error letters
				if ((argv[i][z] < '0' || argv[i][z] > '9') && (argv[i][z] != '-'
						&& argv[i][z] != '+'))
				{
					// Change this !!!!!
					printf("ERROR letters\n");
					exit(EXIT_FAILURE);
				}
				// Error - +
				if ((argv[i][z] == '-' || argv[i][z] == '+') && (argv[i][z + 1] < '0'
						|| argv[i][z + 1] > '9'))
				{
					// Change this !!!!!
					printf("ERROR + or -\n");
					exit(EXIT_FAILURE);
				}
				if (argv[i][z + 1] == ' ' || argv[i][z + 1] == '\0')
					count++;
			}
			z++;
		}
		i++;
	}
	printf("\n");
	printf("Total de números: %d\n", count);
	return (count);
}
