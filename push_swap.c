/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:01:00 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 04:00:32 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	int			nbrs_arg;
	int			*nbrs;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (0);
	if (argc <= 1)
		ft_putstr_fd("Error",1);
	else
	{
		nbrs_arg = count_values(argv, argc);
		stacks->stack_a = start_stack(nbrs_arg);
		stacks->stack_b = start_stack(0);
		nbrs = (int *)malloc((nbrs_arg + 1) * sizeof(int));
		if (!nbrs)
			return (clean_all(stacks, NULL, 0));
		nbrs = add_nbrs(argc, argv, nbrs, nbrs_arg);
		stacks->stack_a = add_nbrs_stack(stacks->stack_a, nbrs, nbrs_arg);
		check_stack(stacks);
	}
	return (clean_all(stacks, nbrs, 0));
}
