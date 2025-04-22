/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:36:50 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:46:16 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_index(t_stack *stack, int nbr)
{
	int		index;
	t_stack	*head;

	index = 0;
	head = stack;
	while (stack != NULL)
	{
		if (nbr > stack->nbr)
			index++;
		stack = stack->next;
	}
	stack = head;
	return (index);
}

t_stack	*add_nbrs_stack(t_stack *stack, int *nbrs, int size)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = stack;
	while (i < size)
	{
		stack->nbr = nbrs[i];
		stack = stack->next;
		i++;
	}
	stack = head;
	i = 0;
	while (i < size)
	{
		stack->index = first_index(head, stack->nbr);
		stack = stack->next;
		i++;
	}
	stack = head;
	return (stack);
}

t_stack	*start_stack(int size)
{
	int		i;
	t_stack	*head;
	t_stack	*current;
	t_stack	*new_node;

	head = NULL;
	current = NULL;
	i = 0;
	while (i < size)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			free(head);
		new_node->nbr = 0;
		new_node->index = -1;
		new_node->next = NULL;
		if (head == NULL)
			head = new_node;
		else
			current->next = new_node;
		current = new_node;
		i++;
	}
	return (head);
}
