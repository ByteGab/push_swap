/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:53:10 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/12 17:39:08 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ra (rotate a)
void	ra(t_stacks *stacks, int flag)
{
	t_stack	*head;
	t_stack	*last_stack;

	if (!stacks->stack_a || !stacks->stack_a->next)
	{
		printf("Vacio stacks->stack_a\n"); // quitar
		return ;
	}
	head = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	last_stack = stacks->stack_a;
	while (last_stack->next != NULL)
		last_stack = last_stack->next;
	last_stack->next = head;
	head->next = NULL;
	if (flag == 1)
		printf("ra\n");
}

// rb (rotate b)
void	rb(t_stacks *stacks, int flag)
{
	t_stack	*head;
	t_stack	*last_stack;

	if (!stacks->stack_b || !stacks->stack_b->next)
	{
		printf("Vacio stacks->stack_b\n"); // quitar
		return ;
	}
	head = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	last_stack = stacks->stack_b;
	while (last_stack->next != NULL)
		last_stack = last_stack->next;
	last_stack->next = head;
	head->next = NULL;
	if (flag == 1)
		printf("rb\n");
}
// rr (ra and rb)
void	rr(t_stacks *stacks)
{
	ra(stacks, 0);
	rb(stacks, 0);
	printf("rr\n");
}