/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:28:08 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/04 02:11:22 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a)
t_stack	*sa(t_stack *stack_a)
{
	t_stack	*swap;

	if (!stack_a || !stack_a->next)
		return (stack_a);

	swap = stack_a;
	stack_a = stack_a->next;
	swap->next = stack_a->next;
	stack_a->next = swap;
	printf("sa\n");
	return(stack_a);
}

// sb (swap b)
void	sb(t_stack *stack_b)
{
	int	swap;
	/*
	if (len_stack_b <= 1)
		return ;
	*/
	swap = stack_b->nbr;
	stack_b->nbr = stack_b->next->nbr;
	stack_b->next->nbr = swap;
	printf("sb\n");
}

// ss (swap a and swap b)
void	ss(t_stack *stack_a, t_stack *stack_b)
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
t_stack	*ra(t_stack *stack_a)
{
	t_stack *head;
    t_stack *last_stack;

    if (!stack_a || !stack_a->next) // stack_a < 2
        return stack_a;

    head = stack_a;
    stack_a = stack_a->next;
    last_stack = stack_a;

    while (last_stack->next != NULL)
        last_stack = last_stack->next;

    last_stack->next = head;
    head->next = NULL;

    printf("ra\n");
    return (stack_a);
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
void	rr(t_stack *stack_a, int *b)
{
	ra(stack_a);
	rb(b);
	printf("rr");
}

// rra (reverse rotate a)
t_stack	*rra(t_stack *stack_a)
{ 
	// arreglar
	t_stack *head;
    t_stack *last_stack;
	t_stack *antlast_stack;

    if (!stack_a || !stack_a->next) // stack_a < 2
        return stack_a;

    head = stack_a;
    stack_a = stack_a->next;
    last_stack = stack_a;
	antlast_stack = stack_a;

    while (last_stack->next != NULL)
        last_stack = last_stack->next;
	while (antlast_stack->next->next != NULL)
        antlast_stack = antlast_stack->next;

	antlast_stack->next = NULL;
    last_stack->next = head;
    stack_a = last_stack;

    printf("rra\n");
    return (stack_a);
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

void	rrr(t_stack *stack_a, int *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	printf("rrr");
}