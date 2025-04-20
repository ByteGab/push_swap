/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 02:43:14 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/20 03:09:21 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stack(t_stack *stack, char *name)
// {
// 	// printf("Contenido de %s:\n", name);
// 	while (stack)
// 	{
// 		// printf("Numero: %d, Indice: %d\n", stack->nbr, stack->index);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }
int	case_rrarb_a(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_place_a(stacks, c))
		i = stacks->size_a - find_place_a(stacks, c);
	i = find_index_b(stacks, c) + i;
	// printf("case_rrarb_a: %d\n", i);
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
	// printf("Calculo rarrb_a: %d\n", i);
	return (i);
}

int	case_rarb_a(t_stacks *stacks, int c)
{
	int	i;

	i = find_place_a(stacks, c);
	if (i < find_index_b(stacks, c))
		i = find_index_b(stacks, c);
	// printf("Debería devolver en rarb: %d\n", i);
	return (i);
}

int	case_rrarrb_a(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_place_a(stacks, c))
		i = stacks->size_a - find_place_a(stacks, c);
	ft_strlen_stack(stacks);
	if ((i < (stacks->size_b - find_index_b(stacks, c))) && find_index_b(stacks,
			c))
		i = stacks->size_b - find_index_b(stacks, c);
	// printf("case_rrarrb_a: %d\n", i);
	return (i);
}
int	rotate_ba(t_stacks *stacks)
{
	int		i;
	t_stack	*tmp;

	// if (!stacks->stack_b) // Valida que stack_b no sea NULL
	// {
	//     printf("Error: stack_b está vacío\n");
	//     return (-1); // Devuelve un valor especial
	// }
	tmp = stacks->stack_b;
	// printf("Es aqui?\n");
	i = case_rrarrb_a(stacks, stacks->stack_b->nbr);
	// print_stack(stacks->stack_a, "Stack a");
	// print_stack(stacks->stack_b, "Stack b");
	// printf("Sale do case_rrarrb_a no rotate: %d\n", i);
	while (tmp)
	{
		// printf("Hola\n");
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
	// printf("rotate ba: %d\n", i);
	// exit(EXIT_FAILURE);
	return (i);
}
void	sort_a(t_stacks *stacks)
{
	int i;
	// t_stack *temp;
	t_stack *temp_b;

	// printf("Entra no sort_a\n");
	// printf("-------------------------------\n");

	while (stacks->stack_b) // Mientras stack_b no esté vacío
	{
		// print_stack(stacks->stack_a, "Stack a");
		// print_stack(stacks->stack_b, "Stack b");
		temp_b = stacks->stack_b; // Apunta al primer nodo de stack_b
		i = rotate_ba(stacks);    // Calcula el mejor movimiento
		// printf("Sale do rotate_ba\n");
		// printf("-------------------------------\n");
		// printf("Entra con valor: %d\n", i);
		// print_stack(stacks->stack_a, "Stack a");
		// print_stack(stacks->stack_b, "Stack b");
		while (i >= 0 && temp_b) // Asegúrate de que temp_b no sea NULL
		{
			// printf("Numero maldito: %d\n", i);
			if (i == case_rarb_a(stacks, temp_b->nbr))
			{
				// printf("Entra no apply_rarb\n");
				i = apply_rarb(stacks, temp_b->nbr, 'b');
				// printf("Sale do apply_rarb\n");
				// print_stack(stacks->stack_a, "stack_a");
				// print_stack(stacks->stack_b, "stack_b");
			}
			else if (i == case_rarrb_a(stacks, temp_b->nbr))
			{
				// printf("Entra no apply_rarrb\n");
				i = apply_rarrb(stacks, temp_b->nbr, 'b');
				// printf("Sale do apply_rarrb\n");
			}
			else if (i == case_rrarrb_a(stacks, temp_b->nbr))
			{
				// printf("Entra no apply_rrarrb\n");
				i = apply_rrarrb(stacks, temp_b->nbr, 'b');
				// printf("Sale do apply_rrarrb\n");
			}
			else if (i == case_rrarb_a(stacks, temp_b->nbr))
			{
				// printf("Entra no apply_rrarb\n");
				i = apply_rrarb(stacks, temp_b->nbr, 'b');
				// printf("Sale do apply_rrarb\n");
			}
			else
			{
				temp_b = temp_b->next; // Avanza al siguiente nodo
			}
		}
	}
	// printf("Acabou ---------------\n");
}