/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:56:54 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:21:07 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks, int flag)
{
	t_stack	*head;
	t_stack	*last_stack;
	t_stack	*antlast_stack;

	if (!stacks->stack_a || !stacks->stack_a->next)
		return ;
	head = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	last_stack = stacks->stack_a;
	antlast_stack = stacks->stack_a;
	while (last_stack->next != NULL)
		last_stack = last_stack->next;
	while (antlast_stack->next->next != NULL)
		antlast_stack = antlast_stack->next;
	antlast_stack->next = NULL;
	last_stack->next = head;
	stacks->stack_a = last_stack;
	if (flag == 1)
		ft_putstr_fd("rra", 1);
}

void	rrb(t_stacks *stacks, int flag)
{
	t_stack	*head;
	t_stack	*last_stack;
	t_stack	*antlast_stack;

	if (!stacks->stack_b || !stacks->stack_b->next)
		return ;
	head = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	last_stack = stacks->stack_b;
	antlast_stack = stacks->stack_b;
	while (last_stack->next != NULL)
		last_stack = last_stack->next;
	while (antlast_stack->next->next != NULL)
		antlast_stack = antlast_stack->next;
	antlast_stack->next = NULL;
	last_stack->next = head;
	stacks->stack_b = last_stack;
	if (flag == 1)
		ft_putstr_fd("rrb", 1);
}

void	rrr(t_stacks *stacks)
{
	rra(stacks, 0);
	rrb(stacks, 0);
	ft_putstr_fd("rrr", 1);
}
