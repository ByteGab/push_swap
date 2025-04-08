/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:50:55 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/08 02:37:34 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// sa (swap a)
void	sa(t_stacks *stacks, int flag)
{
	t_stack	*swap;
	t_stack	*nxt;

	if (!stacks->stack_a || !stacks->stack_a->next)
	{
		printf("Vacio stacks->stack_a\n"); // quitar
		return ;
	}
	swap = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	nxt = stacks->stack_a->next;
	stacks->stack_a->next = swap;
	swap->next = nxt;
	if (flag == 1)
		printf("sa\n");
}
// sb (swap b)
void	sb(t_stacks *stacks, int flag)
{
	t_stack	*swap;
	t_stack	*nxt;

	if (!stacks->stack_b || !stacks->stack_b->next)
	{
		printf("Vacio stacks->stack_b\n"); // quitar
		return ;
	}
	swap = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	nxt = stacks->stack_b->next;
	stacks->stack_b->next = swap;
	swap->next = nxt;
	if (flag == 1)
		printf("sb\n");
}
// ss (swap a and swap b)
void	ss(t_stacks *stacks)
{
	sa(stacks, 0);
	sb(stacks, 0);
	printf("ss\n");
}