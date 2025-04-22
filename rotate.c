/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:53:10 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:18:31 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a)
void	ra(t_stacks *stacks, int flag)
{
	t_stack	*head;
	t_stack	*last;

	if (!stacks->stack_a || !stacks->stack_a->next)
		return ;
	head = stacks->stack_a;
	last = stacks->stack_a;
	while (last->next)
		last = last->next;
	stacks->stack_a = head->next;
	head->next = NULL;
	last->next = head;
	if (flag == 1)
		ft_putstr_fd("ra", 1);
}

// rb (rotate b)
void	rb(t_stacks *stacks, int flag)
{
	t_stack	*head;
	t_stack	*last_stack;

	if (!stacks->stack_b || !stacks->stack_b->next)
		return ;
	head = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	last_stack = stacks->stack_b;
	while (last_stack->next != NULL)
		last_stack = last_stack->next;
	last_stack->next = head;
	head->next = NULL;
	if (flag == 1)
		ft_putstr_fd("rb", 1);
}

void	rr(t_stacks *stacks)
{
	ra(stacks, 0);
	rb(stacks, 0);
	ft_putstr_fd("rr", 1);
}
