/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_sort_cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 00:38:37 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 00:42:40 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rrarb_a(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_place_a(stacks, c))
		i = stacks->size_a - find_place_a(stacks, c);
	i = find_index_b(stacks, c) + i;
	return (i);
}

int	case_rarrb_a(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_index_b(stacks, c))
		i = stacks->size_b - find_index_b(stacks, c);
	i = find_place_a(stacks, c) + i;
	return (i);
}

int	case_rarb_a(t_stacks *stacks, int c)
{
	int	i;

	i = find_place_a(stacks, c);
	if (i < find_index_b(stacks, c))
		i = find_index_b(stacks, c);
	return (i);
}

int	case_rrarrb_a(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_place_a(stacks, c))
		i = stacks->size_a - find_place_a(stacks, c);
	ft_strlen_stack(stacks);
	if ((i < (stacks->size_b - find_index_b(stacks, c))) && find_index_b(stacks,
			c))
		i = stacks->size_b - find_index_b(stacks, c);
	return (i);
}
