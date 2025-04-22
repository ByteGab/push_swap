/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:38:39 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:26:06 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_a(t_stacks *stacks, int nbr)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = stacks->stack_a;
	if (!temp)
		return (-1);
	while (temp)
	{
		if (temp->nbr == nbr)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}

int	find_place_a(t_stacks *stacks, int nbr_push)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp_a;

	i = 1;
	tmp_a = stacks->stack_a;
	if (nbr_push < stacks->stack_a->nbr
		&& nbr_push > last_stack(stacks->stack_a)->nbr)
		i = 0;
	else if (nbr_push > max_stack(stacks->stack_a)
		|| nbr_push < min_stack(stacks->stack_a))
		i = find_index_a(stacks, min_stack(stacks->stack_a));
	else
	{
		tmp = tmp_a->next;
		while (tmp != NULL && tmp_a != NULL && (tmp_a->nbr > nbr_push
				|| tmp->nbr < nbr_push))
		{
			tmp_a = tmp_a->next;
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
