/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:53:10 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/14 21:41:25 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ra (rotate a)
void	ra(t_stacks *stacks, int flag)
{
	t_stack *head;
    t_stack *last;

    if (!stacks->stack_a || !stacks->stack_a->next)
        return; // Nada que rotar si la pila está vacía o tiene un solo elemento

    head = stacks->stack_a;
    last = stacks->stack_a;

    while (last->next) // Encuentra el último nodo
        last = last->next;

    stacks->stack_a = head->next; // Actualiza la cabeza de la pila
    head->next = NULL; // El nodo anterior se convierte en el último
    last->next = head; // Conecta el último nodo con el primero

	if (flag == 1)
		printf("ra\n");
}

// rb (rotate b)
void	rb(t_stacks *stacks, int flag)
{
	t_stack	*head;
	t_stack	*last_stack;

	if (!stacks->stack_b || !stacks->stack_b->next)
	{
		printf("Vacio stacks->stack_b\n"); // quitar
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