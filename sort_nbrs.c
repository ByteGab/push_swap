/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 02:17:58 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/10 06:21:31 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_max(t_stacks *stacks)
{
	int max;
	t_stack	*temp_a;
	
	max = 0;
	temp_a = stacks->stack_a;
	while (temp_a != NULL)
	{
		if (max < temp_a->index)
			max = temp_a->index;	
		temp_a = temp_a->next;
	}
	return (max);
}
void	sort_three(t_stacks *stacks)
{
	int index_max;

	index_max = search_max(stacks);
	if (stacks->stack_a->index == index_max)
		ra(stacks, 1);
	else if (stacks->stack_a->next->index == index_max)
		rra(stacks, 1);
	if (stacks->stack_a->nbr > stacks->stack_a->next->nbr)
		sa(stacks, 1);
}

// void sort_cuatro(t_stacks *stacks)
// {
//     // t_stack *temp_a;
// 	t_stack *temp_b;

//     // Mover el elemento más pequeño (index == 0) a stack_b
//     // temp_a = stacks->stack_a;
//     while (stacks->stack_a != NULL)
//     {
//         if (stacks->stack_a->index == 0)
//         {
//             pb(stacks); // Empujar el elemento más pequeño a stack_b
//             break;
//         }
//         stacks->stack_a = stacks->stack_a->next;
//     }
	
// 	temp_b = stacks->stack_b;
// 	while (temp_b != NULL)
// 	{
// 		printf("Numero: %d", temp_b->nbr);
// 		printf("   Indice: %d", temp_b->index);
// 		printf("\n");
// 		temp_b = temp_b->next;
// 	}
//     // Ordenar los tres elementos restantes en stack_a
// 	 // Asegúrate de tener implementada esta función
//     sort_three(stacks);

//     // Devolver el elemento más pequeño a stack_a
//     pa(stacks);

//     // Rotar si el elemento más pequeño no está en la posición correcta
// 	// Rotar hacia arriba hasta que el índice 0 esté en su lugar
//     if (stacks->stack_a->index != 0)
//         ra(stacks,1); 
// }

void	check_stack(t_stacks *stacks, int size)
{
	int		i;
	int		sort;
	t_stack	*temp_a;

	i = 0;
	sort = 0;
	temp_a = stacks->stack_a;
	while (temp_a != NULL)
	{
		if (i == temp_a->index)
			sort++;
		i++;
		temp_a = temp_a->next;
	}
	// if (sort == size)
	// 	// printf("Esta ordenado\n");
	// else
	// {
		// printf("%d\n",size);
		// printf("No esta ordenado\n");
		if (size == 2)
			sa(stacks, 1);
		else if (size == 3)
			sort_three(stacks);
		else if (size >= 4)
		{
			// sort_cuatro(stacks);
			sort_stacks(stacks);
		}
	// }
}
