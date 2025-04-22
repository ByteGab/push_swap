/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_sort_cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:00:43 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/21 23:03:28 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rrarrb(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_place_b(stacks, c))
		i = stacks->size_b - find_place_b(stacks, c);
	if ((i < (stacks->size_a - find_index_a(stacks, c))) && find_index_a(stacks,
			c))
		i = stacks->size_a - find_place_a(stacks, c);
	return (i);
}

int	case_rarrb(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_place_b(stacks, c))
		i = stacks->size_b - find_place_b(stacks, c);
	i = find_index_a(stacks, c) + i;
	return (i);
}

int	case_rrarb(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_index_a(stacks, c))
		i = stacks->size_a - find_index_a(stacks, c);
	i = find_place_b(stacks, c) + i;
	return (i);
}

int	case_rarb(t_stacks *stacks, int c)
{
	int	i;

	i = find_place_b(stacks, c);
	if (i < find_index_a(stacks, c))
		i = find_index_a(stacks, c);
	return (i);
}
