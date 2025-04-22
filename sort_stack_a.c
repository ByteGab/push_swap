/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 02:43:14 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:25:35 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_ba(t_stacks *stacks)
{
	int		i;
	t_stack	*tmp;

	tmp = stacks->stack_b;
	i = case_rrarrb_a(stacks, stacks->stack_b->nbr);
	while (tmp)
	{
		if (i > case_rarb_a(stacks, tmp->nbr))
			i = case_rarb_a(stacks, tmp->nbr);
		if (i > case_rrarrb_a(stacks, tmp->nbr))
			i = case_rrarrb_a(stacks, tmp->nbr);
		if (i > case_rarrb_a(stacks, tmp->nbr))
			i = case_rarrb_a(stacks, tmp->nbr);
		if (i > case_rrarb_a(stacks, tmp->nbr))
			i = case_rrarb_a(stacks, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

void	sort_a(t_stacks *stacks)
{
	int		i;
	t_stack	*temp_b;

	while (stacks->stack_b)
	{
		temp_b = stacks->stack_b;
		i = rotate_ba(stacks);
		while (i >= 0 && temp_b)
		{
			if (i == case_rarb_a(stacks, temp_b->nbr))
				i = apply_rarb(stacks, temp_b->nbr, 'b');
			else if (i == case_rarrb_a(stacks, temp_b->nbr))
				i = apply_rarrb(stacks, temp_b->nbr, 'b');
			else if (i == case_rrarrb_a(stacks, temp_b->nbr))
				i = apply_rrarrb(stacks, temp_b->nbr, 'b');
			else if (i == case_rrarb_a(stacks, temp_b->nbr))
				i = apply_rrarb(stacks, temp_b->nbr, 'b');
			else
				temp_b = temp_b->next;
		}
	}
}
