/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:41:05 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:25:47 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_b(t_stacks *stacks, int nbr)
{
	int		i;
	t_stack	*temp;

	temp = stacks->stack_b;
	i = 0;
	while (temp->nbr != nbr)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	find_place_b(t_stacks *stacks, int nbr_push)
{
	int		i;
	t_stack	*tmp;
	t_stack	*head;

	i = 1;
	if (nbr_push > stacks->stack_b->nbr
		&& nbr_push < last_stack(stacks->stack_b)->nbr)
		i = 0;
	else if (nbr_push > max_stack(stacks->stack_b)
		|| nbr_push < min_stack(stacks->stack_b))
		i = find_index_b(stacks, max_stack(stacks->stack_b));
	else
	{
		head = stacks->stack_b;
		tmp = head->next;
		while (tmp && (head->nbr < nbr_push || tmp->nbr > nbr_push))
		{
			head = head->next;
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
