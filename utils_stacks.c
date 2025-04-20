/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:22:32 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/20 03:05:29 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_stack(t_stack *stack_a) // change names variable
{
	int min_a;
	min_a = stack_a->nbr;
	while (stack_a != NULL)
	{
		if (stack_a->nbr > min_a)
			min_a = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (min_a);
}

int	min_stack(t_stack *stack_a) // change names variables
{
	int max_a;
	max_a = stack_a->nbr;
	while (stack_a != NULL)
	{
		if (stack_a->nbr < max_a)
			max_a = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (max_a);
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
void	sort_stacks(t_stacks *stacks)
{
	int i;

	i = 0;
	ft_strlen_stack(stacks);
	// first sort
	sort_b(stacks);
	// printf("sort_b\n");
	// print_stack(stacks->stack_a, "Stack a");
	// print_stack(stacks->stack_b, "Stack b");
	// printf("----------------------------------------\n");
	// ft_sort_a
	sort_a(stacks);
	// printf("sort_a\n");
	i = find_place_a(stacks, min_stack(stacks->stack_a));
	ft_strlen_stack(stacks);
	// print_stack(stacks->stack_a, "stack a");
	if (i < stacks->size_a - i)
	{
		while (stacks->stack_a->nbr != min_stack(stacks->stack_a))
			ra(stacks, 1);
	}
	else
	{
		ft_strlen_stack(stacks);
		while (stacks->stack_a->nbr != min_stack(stacks->stack_a))
			rra(stacks, 1);
	}
}