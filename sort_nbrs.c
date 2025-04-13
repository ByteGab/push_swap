/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 02:17:58 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/13 05:37:57 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_max(t_stacks *stacks)
{
	int max;
	t_stack	*temp_a;
	
	max = 0;
	temp_a = stacks->stack_a;
	while (temp_a != NULL)
	{
		if (max < temp_a->index)
			max = temp_a->index;	
		temp_a = temp_a->next;
	}
	return (max);
}
void	sort_three(t_stacks *stacks)
{
	int index_max;

	index_max = search_max(stacks);
	if (stacks->stack_a->index == index_max)
		ra(stacks, 1);
	else if (stacks->stack_a->next->index == index_max)
		rra(stacks, 1);
	if (stacks->stack_a->nbr > stacks->stack_a->next->nbr)
		sa(stacks, 1);
}
void	sort_three_b(t_stacks *stacks)
{
	int index_max;

	index_max = max_stack(stacks->stack_b);
	if (stacks->stack_b->index == index_max)
		rb(stacks, 1);
	else if (stacks->stack_b->next->index == index_max)
		rrb(stacks, 1);
	if (stacks->stack_b->nbr > stacks->stack_b->next->nbr)
		sb(stacks, 1);
}
void	check_stack(t_stacks *stacks)
{
	int		i;
	int		sort;
	t_stack	*temp_a;

	i = 0;
	sort = 0;
	temp_a = stacks->stack_a;
	while (temp_a != NULL)
	{
		if (i == temp_a->index)
			sort++;
		i++;
		temp_a = temp_a->next;
	}
	ft_strlen_stack(stacks);
	if (sort == stacks->size_a)
		printf("Esta ordenado\n");
	else
	{
		if ((stacks->size_a == 2))
			sa(stacks, 1);
		else if ((stacks->size_a) == 3)
			sort_three(stacks);
		else if (stacks->size_a >= 4)
			sort_stacks(stacks);
	}
}
