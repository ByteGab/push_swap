/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 02:43:14 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/13 09:26:12 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rrarb_a(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_place_a(stacks, c))
		i = stacks->size_a - find_place_a(stacks, c);
	i = find_index_b(stacks, c) + i;
	printf("case_rrarb_a: %d\n",i);
	return (i);
}
int	case_rarrb_a(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_index_b(stacks, c))
		i = stacks->size_b - find_index_b(stacks, c);
	i = find_place_a(stacks, c) + i;
	printf("Calculo rarrb_a: %d\n", i);
	return (i);
}

int	case_rarb_a(t_stacks *stacks, int c)
{
	int	i;

	i = find_place_a(stacks, c);
	if (i < find_index_b(stacks, c))
		i = find_index_b(stacks, c);
	printf("case_rarb_a: %d\n",i);
	return (i);
}

int	case_rrarrb_a(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_place_a(stacks, c))
		i = stacks->size_a - find_place_a(stacks, c);
	if ((i < (stacks->size_b - find_index_b(stacks, c))) && find_index_b(stacks,
			c))
		i = stacks->size_b - find_index_b(stacks, c);
	printf("case_rrarrb_a: %d\n",i);
	return (i);
}
int	rotate_ba(t_stacks *stacks)
{
	int		i;
	t_stack	*tmp;
    
    tmp = stacks->stack_b;
	i = case_rrarrb_a(stacks, stacks->stack_b->nbr);
	printf("Sale do case_rrarrb_a no rotate: %d\n",i);
	while (tmp)
	{
		printf("Hola\n");
		if (i > case_rarb_a(stacks, tmp->nbr))
			i = case_rarb_a(stacks, tmp->nbr);
		if (i > case_rrarrb_a(stacks, tmp->nbr))
			i = case_rrarrb_a(stacks, tmp->nbr);
		if (i > case_rarrb_a(stacks, tmp->nbr))
			i = case_rarrb_a(stacks, tmp->nbr);
		if (i > case_rrarb_a(stacks, tmp->nbr))
			i = case_rrarb_a(stacks, tmp->nbr);
		tmp = tmp->next;
	}
	printf("rotate ba: %d\n",i);
	// exit(EXIT_FAILURE);
	return (i);
}
void	sort_a(t_stacks *stacks)
{
	int i;
	t_stack *temp;
	t_stack *temp_b;
	printf("Entra no sort_a\n");
	temp = stacks->stack_b;
	while (temp)
	{
		temp_b = stacks->stack_b;
		i = rotate_ba(stacks);
		printf("Sale do rotate_ba\n");
		while (i >= 0)
		{
			if (i == case_rarb_a(stacks, temp_b->nbr))
			{
				printf("Entra no apply_rarb\n");
				i = apply_rarb(stacks, temp_b->nbr, 'b');
				printf("Sale do apply_rarb\n");
			}
			else if (i == case_rarrb_a(stacks, temp_b->nbr))
			{
				printf("Entra no apply_rarrb\n");
				i = apply_rarrb(stacks, temp_b->nbr, 'b');
				printf("Sale do apply_rarrb\n");
			}
			else if (i == case_rrarrb_a(stacks, temp_b->nbr))
			{
				printf("Entra no apply_rrarrb\n");
				i = apply_rrarrb(stacks, temp_b->nbr, 'b');
				printf("Sale do apply_rrarrb\n");
			}
			else if (i == case_rrarb_a(stacks, temp_b->nbr))
			{
				printf("Entra no apply_rrarrb\n");
				i = apply_rrarb(stacks, temp_b->nbr, 'b');
				printf("Sale do apply_rrarrb\n");
			}
			else
				temp_b = temp_b->next;
		}
	}
	printf("Acabou ---------------\n");
}