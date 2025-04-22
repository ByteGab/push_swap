/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:50:55 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:19:20 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks, int flag)
{
	t_stack	*swap;
	t_stack	*nxt;

	if (!stacks->stack_a || !stacks->stack_a->next)
		return ;
	swap = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	nxt = stacks->stack_a->next;
	stacks->stack_a->next = swap;
	swap->next = nxt;
	if (flag == 1)
		ft_putstr_fd("sa", 1);
}

void	sb(t_stacks *stacks, int flag)
{
	t_stack	*swap;
	t_stack	*nxt;

	if (!stacks->stack_b || !stacks->stack_b->next)
		return ;
	swap = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	nxt = stacks->stack_b->next;
	stacks->stack_b->next = swap;
	swap->next = nxt;
	if (flag == 1)
		ft_putstr_fd("sb", 1);
}

void	ss(t_stacks *stacks)
{
	sa(stacks, 0);
	sb(stacks, 0);
	ft_putstr_fd("ss", 1);
}
