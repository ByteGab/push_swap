/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:36:50 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/02 23:22:10 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*start_stack(int size)
{
	int i;
    t_stack *head; // puntero de la cabeza de la lista
    t_stack *current; // recorrer y enlazar los nodos
	t_stack *new_node; // new node

    head = NULL;
    printf("Tamaño lista: %d\n", size);
	i = 0;
	while (i < size)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		// if (!new_stack)
		//     free();
        new_node->nbr = 0;
        new_node->index = -1;
		new_node->next = NULL;

        // si es el primer nodo, se asigna como cabeza
        if (head == NULL)
            head = new_node;
        // se enlaza el nuevo nodo al final de la lista
        else
            current->next = new_node;
        // actualizamos el puntero current para que apunte al nuevo nodo
        current = new_node;
		i++;
	}
    return (head);
}