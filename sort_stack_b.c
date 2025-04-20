/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 05:57:57 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/20 00:59:48 by gafreire         ###   ########.fr       */
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
	// printf("%d\n", temp->nbr);
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
	printf("Acabou rotate_ab: %d\n",i);
	return (i);
}
void	sort_b_next(t_stacks *stacks)
{
	int		i;
	t_stack	*temp;

	ft_strlen_stack(stacks);
	while (stacks->size_a > 3 && !check_sort(stacks->stack_a)) // check short
	{
		ft_strlen_stack(stacks);
		temp = stacks->stack_a;
		printf("LLega al bucle\n");
		i = rotate_ab(stacks);
		printf("Saliu de rotate_ab\n");
		while (i >= 0)
		{
			if (i == case_rarb(stacks, temp->nbr))
			{
				printf("entrou no case_rarb\n");
				i = apply_rarb(stacks, temp->nbr, 'a');
			}
			else if (i == case_rrarrb(stacks, temp->nbr))
			{
				printf("entrou no case_rrarrb\n");
				i = apply_rrarrb(stacks, temp->nbr, 'a');
			}
			else if (i == case_rarrb(stacks, temp->nbr))
			{
				printf("entrou no case_rarrb\n");
				i = apply_rarrb(stacks, temp->nbr, 'a');
			}
			else if (i == case_rrarb(stacks, temp->nbr))
			{
				printf("entrou no case_rrarb\n");
				i = apply_rrarb(stacks, temp->nbr, 'a');
			}
			else
			{
				printf("Next\n");
				temp = temp->next;
			}
			printf("Final sort_b_next\n");
		}
	}
}
void	sort_b(t_stacks *stacks)
{
	// create min_stack_b and max_stack_b
	// printf("Min stack_b: %d\n",min_stack(stacks->stack_b));
	// printf("Max stack_b: %d\n",max_stack(stacks->stack_b));

	ft_strlen_stack(stacks);
	if (stacks->size_a > 3 && !check_sort(stacks->stack_a)) // check_short
	{
		pb(stacks);
		print_stack(stacks->stack_a,"Stack a");
		print_stack(stacks->stack_b,"Stack b");
	}
	ft_strlen_stack(stacks);
	if (stacks->size_a > 3 && !check_sort(stacks->stack_a)) // check_short
	{
		pb(stacks);
		print_stack(stacks->stack_a,"Stack a");
		print_stack(stacks->stack_b,"Stack b");
	}
	ft_strlen_stack(stacks);
	if (stacks->size_a > 3 && !check_sort(stacks->stack_a))
	{
		// printf("Entra en el algoritmo b\n");
		sort_b_next(stacks);
	}
	ft_strlen_stack(stacks);
	if (!check_sort(stacks->stack_a))
	{
		// printf("Entra en el algoritmo de tres b\n");
		sort_three_b(stacks);
	}
}
