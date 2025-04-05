/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:28:08 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/05 02:05:41 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a)
void	sa(t_stacks *stacks, int flag)
{
	t_stack	*swap;
	t_stack	*nxt;

	if (!stacks->stack_a || !stacks->stack_a->next)
	{
		printf("Vacio stacks->stack_a\n");
		// return (stacks->stack_a);
	}
	swap = stacks->stack_a;
	// printf("boiba temporal %d \n", swap->nbr);
	stacks->stack_a = stacks->stack_a->next;
	// printf("boiba new cabeza  %d \n", stacks->stack_a->nbr);
	nxt = stacks->stack_a->next;
	// printf("boiba ter0  %d \n", nxt->nbr);
	stacks->stack_a->next = swap;
	swap->next = nxt;
	// while (stacks->stack_a != NULL)
	// 	{
	// 		printf("num = %d ", stacks->stack_a->nbr);
	// 		printf("i = %d \n", stacks->stack_a->index);
	// 		stacks->stack_a = stacks->stack_a->next;
	// 		sabe++;
	// 	}
	// printf("sab %d\n ", sabe);
	if (flag == 1)
		printf("sa\n");
	// return (stacks->stack_a);
}

// sb (swap b)
void	sb(t_stacks *stacks, int flag)
{
	t_stack	*swap;
	t_stack	*nxt;

	if (!stacks->stack_b || !stacks->stack_b->next)
	{
		printf("Vacio stacks->stack_b\n");
		exit(EXIT_FAILURE);
	}
	swap = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	nxt = stacks->stack_b->next;
	stacks->stack_b->next = swap;
	swap->next = nxt;
	if (flag == 1)
		printf("sb\n");
	// return (stacks->stack_a);
}
// ss (swap a and swap b)
void	ss(t_stacks *stacks)
{
	sa(stacks, 0);
	sb(stacks, 0);
	printf("ss\n");
}
// ra (rotate a)
void	ra(t_stacks *stacks)
{
	t_stack	*head;
	t_stack	*last_stack;

	if (!stacks->stack_a || !stacks->stack_a->next) // stacks->stack_a < 2
		printf("Vacio stacks->stack_a\n");
	head = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	last_stack = stacks->stack_a;
	while (last_stack->next != NULL)
		last_stack = last_stack->next;
	last_stack->next = head;
	head->next = NULL;
	printf("ra\n");
}

// // pa (push a)
// void	pa(int *stacks->stack_a, int *stack_b)
// {
// 	int	swap;
// 	int	i;

// 	int len = 5; // cambiar
// 	i = 1;
// 	if (stack_b == NULL)
// 		return ;
// 	else
// 	{
// 		swap = stacks->stack_a[i];
// 		stacks->stack_a[0] = stack_b[0];
// 		stack_b[0] = 0;
// 		stacks->stack_a[1] = swap;
// 		len++;
// 		while (i < len)
// 		{
// 			stacks->stack_a[i] = stacks->stack_a[i + 1];
// 			i++;
// 		}
// 	}
// 	printf("pa\n");
// }

// // pb (push b)
// void	pb(int *stacks->stack_a, int *stack_b)
// {
// 	int	swap;
// 	int	i;
// 	int	len;

// 	if (stacks->stack_a == NULL)
// 		return ;
// 	else
// 	{
// 		stack_b[0] = stacks->stack_a[0];
// 		while (i < len)
// 		{
// 			swap = stack_b[i];
// 			stack_b[i + 1] = stack_b[i];
// 			i++;
// 		}
// 	}
// 	printf("pb");
// }

// // rb (rotate b)
// void	rb(int *stack_b)
// {
// 	int	swap;
// 	int	len;
// 	int	i;

// 	len = 0;
// 	i = len;
// 	while (i != 0)
// 	{
// 		swap = stack_b[i];
// 		stack_b[i - 1] = stack_b[i];
// 		i--;
// 	}
// 	if (i == 0)
// 		stack_b[len] = stack_b[i];
// 	printf("rb");
// }
// // rr (ra and rb)
// void	rr(t_stack *stacks->stack_a, int *b)
// {
// 	ra(stacks->stack_a);
// 	rb(b);
// 	printf("rr");
// }

// // rra (reverse rotate a)
// t_stack	*rra(t_stack *stacks->stack_a)
// {
// 	t_stack	*head;
// 	t_stack	*last_stack;
// 	t_stack	*antlast_stack;

// 	// arreglar
// 	if (!stacks->stack_a || !stacks->stack_a->next) // stacks->stack_a < 2
// 		return (stacks->stack_a);
// 	head = stacks->stack_a;
// 	stacks->stack_a = stacks->stack_a->next;
// 	last_stack = stacks->stack_a;
// 	antlast_stack = stacks->stack_a;
// 	while (last_stack->next != NULL)
// 		last_stack = last_stack->next;
// 	while (antlast_stack->next->next != NULL)
// 		antlast_stack = antlast_stack->next;
// 	antlast_stack->next = NULL;
// 	last_stack->next = head;
// 	stacks->stack_a = last_stack;
// 	printf("rra\n");
// 	return (stacks->stack_a);
// }

// // rrb (reverse rotate b)
// void	rrb(int *stack_b)
// {
// 	int	swap;
// 	int	len;
// 	int	i;

// 	i = 0;
// 	if (i == 0)
// 		stack_b[0] = stack_b[len];
// 	while (i <= len)
// 	{
// 		swap = stack_b[i];
// 		stack_b[i + 1] = stack_b[i];
// 		i++;
// 	}
// 	printf("rrb");
// }

// void	rrr(t_stack *stacks->stack_a, int *stack_b)
// {
// 	rra(stacks->stack_a);
// 	rrb(stack_b);
// 	printf("rrr");
// }