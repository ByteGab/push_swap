/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 00:27:38 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 03:54:06 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nbrs(char **nbrs)
{
	int	i;

	i = 0;
	while ((nbrs[i] != NULL))
	{
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int	clean_all(t_stacks *stacks, int *nbrs, int value)
{
	if (stacks != NULL)
	{
		free_stack(stacks->stack_a);
		free_stack(stacks->stack_b);
		free(stacks);
	}
	free(nbrs);
	return (value);
}
