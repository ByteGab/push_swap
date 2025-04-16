/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:54:57 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/15 09:36:23 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa (push a)
void	pa(t_stacks *stacks)
{
	t_stack	*swap;

	if (!stacks->stack_b)
		return ;
	swap = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	swap->next = stacks->stack_a;
	stacks->stack_a = swap;

	stacks->size_a++; // Actualiza los tamaños
    stacks->size_b--;
	printf("pa\n");
}

// pb (push b)
void	pb(t_stacks *stacks)
{
	t_stack *swap;

	if (!stacks->stack_a)
		return ;
	swap = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	swap->next = stacks->stack_b;
	stacks->stack_b = swap;

	stacks->size_a--; // Actualiza los tamaños
    stacks->size_b++;
	printf("pb\n");
}