/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:53:05 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:23:41 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stacks *stacks)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	sort_b(stacks);
	sort_a(stacks);
	i = find_place_a(stacks, min_stack(stacks->stack_a));
	ft_strlen_stack(stacks);
	if (i < stacks->size_a - i)
	{
		while (stacks->stack_a->nbr != min_stack(stacks->stack_a))
			ra(stacks, 1);
	}
	else
	{
		ft_strlen_stack(stacks);
		while (stacks->stack_a->nbr != min_stack(stacks->stack_a))
			rra(stacks, 1);
	}
}
