/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 00:43:39 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/22 16:14:59 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_rarb(t_stacks *stacks, int c, char s)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		place;
	int		place_b;

	temp_a = stacks->stack_a;
	temp_b = stacks->stack_b;
	if (s == 'a')
	{
		while (temp_a->nbr != c && find_place_b(stacks, c) > 0)
		{
			rr(stacks);
			temp_a = stacks->stack_a;
		}
		while (temp_a->nbr != c)
		{
			ra(stacks, 1);
			temp_a = stacks->stack_a;
		}
		place = find_place_b(stacks, c);
		while (place-- > 0)
		{
			rb(stacks, 1);
			temp_a = stacks->stack_a;
		}
		pb(stacks);
	}
	else
	{
		while (temp_b->nbr != c && find_place_a(stacks, c) > 0)
		{
			rr(stacks);
			temp_b = stacks->stack_b;
		}
		while (temp_b->nbr != c)
		{
			rb(stacks, 1);
			temp_b = stacks->stack_b;
		}
		place_b = find_place_a(stacks, c);
		while (place_b-- > 0)
		{
			ra(stacks, 1);
			temp_b = stacks->stack_b;
		}
		pa(stacks);
	}
	return (-1);
}

int	apply_rrarrb(t_stacks *stacks, int c, char s)
{
	if (s == 'a')
	{
		while (stacks->stack_a->nbr != c && find_place_b(stacks, c > 0))
			rrr(stacks);
		while (stacks->stack_a->nbr != c)
			rra(stacks, 1);
		while (find_place_b(stacks, c) > 0)
			rrb(stacks, 1);
		pb(stacks);
	}
	else
	{
		while (stacks->stack_b->nbr != c && find_place_a(stacks, c) > 0)
			rrr(stacks);
		while (stacks->stack_b->nbr != c)
			rrb(stacks, 1);
		while (find_place_a(stacks, c) > 0)
			rra(stacks, 1);
		pa(stacks);
	}
	return (-1);
}

int	apply_rarrb(t_stacks *stacks, int c, char s)
{
	if (s == 'a')
	{
		while (stacks->stack_a->nbr != c)
			ra(stacks, 1);
		while (find_place_b(stacks, c) > 0)
			rrb(stacks, 1);
		pb(stacks);
	}
	else
	{
		while (find_place_a(stacks, c) > 0)
			ra(stacks, 1);
		while (stacks->stack_b->nbr != c)
			rrb(stacks, 1);
		pa(stacks);
	}
	return (-1);
}

int	apply_rrarb(t_stacks *stacks, int c, char s)
{
	if (s == 'a')
	{
		while (stacks->stack_a->nbr != c)
			rra(stacks, 1);
		while (find_place_b(stacks, c) > 0)
			rb(stacks, 1);
		pb(stacks);
	}
	else
	{
		while (find_place_a(stacks, c) > 0)
			rra(stacks, 1);
		while (stacks->stack_b->nbr != c)
			rb(stacks, 1);
		pa(stacks);
	}
	return (-1);
}
