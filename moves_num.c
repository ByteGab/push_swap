/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:28:08 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/06 19:50:57 by gafreire         ###   ########.fr       */
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
		return ;
	}
	swap = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	nxt = stacks->stack_a->next;
	stacks->stack_a->next = swap;
	swap->next = nxt;
	if (flag == 1)
		printf("sa\n");
}
// sb (swap b)
void	sb(t_stacks *stacks, int flag)
{
	t_stack	*swap;
	t_stack	*nxt;

	if (!stacks->stack_b || !stacks->stack_b->next)
	{
		printf("Vacio stacks->stack_b\n");
		return ;
	}
	swap = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	nxt = stacks->stack_b->next;
	stacks->stack_b->next = swap;
	swap->next = nxt;
	if (flag == 1)
		printf("sb\n");
}
// ss (swap a and swap b)
void	ss(t_stacks *stacks)
{
	sa(stacks, 0);
	sb(stacks, 0);
	printf("ss\n");
}

// pa (push a)
void	pa(t_stacks *stacks)
{
	t_stack *swap;

    if (!stacks->stack_b) // Si la pila A está vacía, no se hace nada.
        return;

    // Guardamos el nodo superior de stack_a.
    swap = stacks->stack_b;

    // Actualizamos stack_a para que apunte al siguiente nodo.
    stacks->stack_b = stacks->stack_b->next;

    // Insertamos el nodo en la cabecera de stack_b.
    swap->next = stacks->stack_a;
    stacks->stack_a = swap;
	printf("pa\n");
}

// pb (push b)
void	pb(t_stacks *stacks)
{
	t_stack *swap;

    if (!stacks->stack_a) // Si la pila A está vacía, no se hace nada.
        return ;

    // Guardamos el nodo superior de stack_a.
    swap = stacks->stack_a;

    // Actualizamos stack_a para que apunte al siguiente nodo.
    stacks->stack_a = stacks->stack_a->next;

    // Insertamos el nodo en la cabecera de stack_b.
    swap->next = stacks->stack_b;
    stacks->stack_b = swap;
	printf("pb\n");
}

// ra (rotate a)
void	ra(t_stacks *stacks, int flag)
{
	t_stack	*head;
	t_stack	*last_stack;

	if (!stacks->stack_a || !stacks->stack_a->next) // stacks->stack_a < 2
	{
		printf("Vacio stacks->stack_a\n");
		return ;
	}
	head = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	last_stack = stacks->stack_a;
	while (last_stack->next != NULL)
		last_stack = last_stack->next;
	last_stack->next = head;
	head->next = NULL;
	if (flag == 1)
		printf("ra\n");
}

// rb (rotate b)
void	rb(t_stacks *stacks, int flag)
{
	t_stack	*head;
	t_stack	*last_stack;

	if (!stacks->stack_b || !stacks->stack_b->next) // stacks->stack_a < 2
	{
		printf("Vacio stacks->stack_b\n");
		return ;
	}
	head = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	last_stack = stacks->stack_b;
	while (last_stack->next != NULL)
		last_stack = last_stack->next;
	last_stack->next = head;
	head->next = NULL;
	if (flag == 1)
		printf("rb\n");
}
// rr (ra and rb)
void	rr(t_stacks *stacks)
{
	ra(stacks, 0);
	rb(stacks, 0);
	printf("rr\n");
}

// rra (reverse rotate a)
void	rra(t_stacks *stacks,int flag)
{
	t_stack	*head;
	t_stack	*last_stack;
	t_stack	*antlast_stack;

	// arreglar
	if (!stacks->stack_a || !stacks->stack_a->next) // stacks->stack_a < 2
	{
		printf("Vacio stacks->stack_a\n");
		return ;
	}
	head = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	last_stack = stacks->stack_a;
	antlast_stack = stacks->stack_a;
	while (last_stack->next != NULL)
		last_stack = last_stack->next;
	while (antlast_stack->next->next != NULL)
		antlast_stack = antlast_stack->next;
	antlast_stack->next = NULL;
	last_stack->next = head;
	stacks->stack_a = last_stack;
	if (flag == 1)
		printf("rra\n");
}

// rrb (reverse rotate b)
void	rrb(t_stacks *stacks,int flag)
{
	t_stack	*head;
	t_stack	*last_stack;
	t_stack	*antlast_stack;

	// arreglar
	if (!stacks->stack_b || !stacks->stack_b->next) // stacks->stack_a < 2
	{
		printf("Vacio stacks->stack_b\n");
		return ;
	}
	head = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	last_stack = stacks->stack_b;
	antlast_stack = stacks->stack_b;
	while (last_stack->next != NULL)
		last_stack = last_stack->next;
	while (antlast_stack->next->next != NULL)
		antlast_stack = antlast_stack->next;
	antlast_stack->next = NULL;
	last_stack->next = head;
	stacks->stack_b = last_stack;
	if (flag == 1)
		printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	rra(stacks,0);
	rrb(stacks,0);
	printf("rrr\n");
}