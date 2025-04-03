/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:58:32 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/03 15:30:08 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long    ft_atol(char *nptr)
{
    int	i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\r'
		|| nptr[i] == '\n' || nptr[i] == '\f' || nptr[i] == '\v')
	{
		i++;
	}
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

void	repeat_nbrs(int *nbr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nbr[i] == nbr[j])
			{
				// change this !!!!
				printf("ERROR repeat nbrs\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

int	check_nbrs(char **nbrs_str, char *nbrs, int *nubr)
{
	long	nbr_long;
	int		nbr;

	nbr_long = ft_atol(nbrs);
    if (nbr_long < -2147483648 || nbr_long > 2147483648)
    {
        // change this!!!
        printf("ERROR int max or min\n");
        exit(EXIT_FAILURE);
    }
	nbr = ft_atoi(nbrs);
	printf("%d ", nbr);
	return (nbr);
}

int	*add_nbrs(int argc, char **argv, int *nbrs, int nbrs_arg)
{
	int i;
	int j;
	int z;
	char **total_nbrs;

	i = 1;
	z = 0;
	printf("Numeros en int: ");
	while (i < argc)
	{
		j = 0;
		total_nbrs = ft_split(argv[i], ' ');

		while (total_nbrs[j] != NULL)
		{
			nbrs[z] = check_nbrs(total_nbrs, total_nbrs[j], nbrs);
			j++;
			z++;
		}
		// free total_nbrs
		i++;
	}
	nbrs[z] = '\0';
	printf("\n");
	repeat_nbrs(nbrs, nbrs_arg);
	return (nbrs);
}