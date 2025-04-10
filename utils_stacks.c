/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:22:32 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/10 06:30:47 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_stack(t_stack *stack_a)
{
    int min_a;
    min_a = stack_a->index;
    while (stack_a != NULL)
	{
		if (stack_a->index > min_a)
			min_a = stack_a->index;
		stack_a = stack_a->next;
	}
    return (min_a);
}

int	min_stack(t_stack *stack_a)
{
    int max_a;
    max_a = stack_a->index;
    while (stack_a != NULL)
	{
		if (stack_a->index < max_a)
            max_a = stack_a->index;
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
	ft_strlen_stack(stacks);

	// printf("Size sack_a: %d\n",stacks->size_a);
	// printf("Size sack_b: %d\n",stacks->size_b);

	// if (stacks->size_a > 3) // check cost moves
	//     pb(stacks);
	while (stacks->size_a != 3)
	{
		pb(stacks);
		ft_strlen_stack(stacks);
	}
	sort_three(stacks);
	ft_strlen_stack(stacks);
    
	// printf("int min_a: %d\n", min_stack(stacks->stack_a));
	// printf("int min_b: %d\n", min_stack(stacks->stack_b));
    // printf("int max_a: %d\n", max_stack(stacks->stack_a));
	// printf("int max_a: %d\n", max_stack(stacks->stack_b));

	while (stacks->size_b != 0)
	{
		pa(stacks);
		ft_strlen_stack(stacks);
	}
	ft_strlen_stack(stacks);

	// printf("Size sack_a: %d\n",stacks->size_a);
	// printf("Size sack_b: %d\n",stacks->size_b);
}