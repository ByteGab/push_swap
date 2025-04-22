/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:54:57 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:20:11 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	t_stack	*swap;

	if (!stacks->stack_b)
		return ;
	swap = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	swap->next = stacks->stack_a;
	stacks->stack_a = swap;
	stacks->size_a++;
	stacks->size_b--;
	ft_putstr_fd("pa", 1);
}

void	pb(t_stacks *stacks)
{
	t_stack	*swap;

	if (!stacks->stack_a)
		return ;
	swap = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	swap->next = stacks->stack_b;
	stacks->stack_b = swap;
	stacks->size_a--;
	stacks->size_b++;
	ft_putstr_fd("pb", 1);
}
