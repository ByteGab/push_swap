/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:52:40 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:22:48 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	max_stack(t_stack *stack)
{
	int	min;

	min = stack->nbr;
	while (stack != NULL)
	{
		if (stack->nbr > min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

int	min_stack(t_stack *stack)
{
	int	max;

	max = stack->nbr;
	while (stack != NULL)
	{
		if (stack->nbr < max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

void	ft_strlen_stack(t_stacks *stacks)
{
	int		size_a;
	int		size_b;
	t_stack	*temp_a;
	t_stack	*temp_b;

	size_a = 0;
	size_b = 0;
	temp_a = stacks->stack_a;
	temp_b = stacks->stack_b;
	while (temp_a != NULL)
	{
		size_a++;
		temp_a = temp_a->next;
	}
	while (temp_b != NULL)
	{
		size_b++;
		temp_b = temp_b->next;
	}
	stacks->size_a = size_a;
	stacks->size_b = size_b;
}
