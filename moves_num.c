/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:28:08 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/03 19:24:42 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a)
void	sa(t_stack *stack_a)
{
	int	swap;
	t_stack *head;

	head = stack_a;

	/*
	if (len_stack_a <= 1)
		return ;
	*/
	swap = stack_a->nbr;
	stack_a->nbr = stack_a->next->nbr;
	stack_a->next->nbr = swap;
	stack_a = head;
	printf("sa\n");
}

// sb (swap b)
void	sb(int *stack_b)
{
	int	swap;

	/*
	if (len_stack_b <= 1)
		return ;
	*/
	swap = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = swap;
	printf("sb\n");
}

// ss (swap a and swap b)
void	ss(t_stack *stack_a, int *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	printf("ss\n");
}

// pa (push a)
void	pa(int *stack_a, int *stack_b)
{
	int	swap;
	int	i;
	int	len = 5; // cambiar

    i = 1;
    
	if (stack_b == NULL)
		return ;
	else
	{
        swap = stack_a[i];
		stack_a[0] = stack_b[0];
        stack_b[0] = 0;
        stack_a[1] = swap;
        len++;
		while (i < len)
		{
			stack_a[i] = stack_a[i + 1];
			i++;
		}
	}
	printf("pa\n");
}

// pb (push b)
void	pb(int *stack_a, int *stack_b)
{
	int	swap;
	int	i;
	int	len;

	if (stack_a == NULL)
		return ;
	else
	{
		stack_b[0] = stack_a[0];
		while (i < len)
		{
			swap = stack_b[i];
			stack_b[i + 1] = stack_b[i];
			i++;
		}
	}
	printf("pb");
}

// ra (rotate a)
void	ra(int *stack_a)
{
	int	swap;
	int	len;
	int	i;

	len = 0;
	i = len;
	while (i != 0)
	{
		swap = stack_a[i];
		stack_a[i - 1] = stack_a[i];
		i--;
	}
	if (i == 0)
		stack_a[len] = stack_a[i];
	printf("ra");
}
// rb (rotate b)
void	rb(int *stack_b)
{
	int	swap;
	int	len;
	int	i;

	len = 0;
	i = len;
	while (i != 0)
	{
		swap = stack_b[i];
		stack_b[i - 1] = stack_b[i];
		i--;
	}
	if (i == 0)
		stack_b[len] = stack_b[i];
	printf("rb");
}
// rr (ra and rb)
void	rr(int *a, int *b)
{
	ra(a);
	rb(b);
	printf("rr");
}

// rra (reverse rotate a)
void	rra(int *stack_a)
{
	int	swap;
	int	len;
	int	i;

	i = 0;
	if (i == 0)
		stack_a[0] = stack_a[len];
	while (i <= len)
	{
		swap = stack_a[i];
		stack_a[i + 1] = stack_a[i];
		i++;
	}
	printf("rra");
}

// rrb (reverse rotate b)
void	rrb(int *stack_b)
{
	int	swap;
	int	len;
	int	i;

	i = 0;
	if (i == 0)
		stack_b[0] = stack_b[len];
	while (i <= len)
	{
		swap = stack_b[i];
		stack_b[i + 1] = stack_b[i];
		i++;
	}
	printf("rrb");
}

void	rrr(int *stack_a, int *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	printf("rrr");
}