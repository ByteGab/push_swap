/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 05:57:57 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:23:57 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}

int	rotate_ab(t_stacks *stacks)
{
	int		i;
	t_stack	*temp;

	temp = stacks->stack_a;
	i = case_rrarrb(stacks, stacks->stack_a->nbr);
	while (temp != NULL)
	{
		if (i > case_rarb(stacks, temp->nbr))
			i = case_rarb(stacks, temp->nbr);
		if (i > case_rrarrb(stacks, temp->nbr))
			i = case_rrarrb(stacks, temp->nbr);
		if (i > case_rarrb(stacks, temp->nbr))
			i = case_rarrb(stacks, temp->nbr);
		if (i > case_rrarb(stacks, temp->nbr))
			i = case_rrarb(stacks, temp->nbr);
		temp = temp->next;
	}
	return (i);
}

void	sort_b_next(t_stacks *stacks)
{
	int		i;
	t_stack	*temp;

	ft_strlen_stack(stacks);
	while (stacks->size_a > 3 && !check_sort(stacks->stack_a))
	{
		ft_strlen_stack(stacks);
		temp = stacks->stack_a;
		i = rotate_ab(stacks);
		while (i >= 0)
		{
			if (i == case_rarb(stacks, temp->nbr))
				i = apply_rarb(stacks, temp->nbr, 'a');
			else if (i == case_rrarrb(stacks, temp->nbr))
				i = apply_rrarrb(stacks, temp->nbr, 'a');
			else if (i == case_rarrb(stacks, temp->nbr))
				i = apply_rarrb(stacks, temp->nbr, 'a');
			else if (i == case_rrarb(stacks, temp->nbr))
				i = apply_rrarb(stacks, temp->nbr, 'a');
			else
				temp = temp->next;
		}
	}
}

void	sort_b(t_stacks *stacks)
{
	ft_strlen_stack(stacks);
	if (stacks->size_a > 3 && !check_sort(stacks->stack_a))
		pb(stacks);
	ft_strlen_stack(stacks);
	if (stacks->size_a > 3 && !check_sort(stacks->stack_a))
		pb(stacks);
	ft_strlen_stack(stacks);
	if (stacks->size_a > 3 && !check_sort(stacks->stack_a))
		sort_b_next(stacks);
	ft_strlen_stack(stacks);
	if (!check_sort(stacks->stack_a))
		sort_three_b(stacks);
}
