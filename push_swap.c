/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:01:00 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/13 02:34:51 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack *temp_a;
	t_stack *temp_b;
	t_stacks *stacks;
	int nbrs_arg;
	int *nbrs;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
	{
		// printf("Error al reservar memoria para stacks\n");
		return (1);
	}
	if (argc <= 1)
		printf("ERROR arg\n");
	else
	{
		// printf("Numero de argumentos sin los string: %d\n", argc - 1);
		nbrs_arg = count_valors(argv, argc);
		// init stack
		stacks->stack_a = start_stack(nbrs_arg);
		stacks->stack_b = start_stack(0);
		// free stack_a
		nbrs = (int *)malloc((nbrs_arg + 1) * sizeof(int));
		if (!nbrs)
			free(nbrs);
		// free array nbrs
		nbrs = add_nbrs(argc, argv, nbrs, nbrs_arg);
		stacks->stack_a = add_nbrs_stack(stacks->stack_a, nbrs, nbrs_arg);
		// printf("-----------------------------------------------------------\n");
		check_stack(stacks); // remove nbrs_arg i guess ???
		temp_a = stacks->stack_a;
		while (temp_a != NULL)
		{
			printf("Numero: %d", temp_a->nbr);
			printf("   Indice: %d", temp_a->index);
			printf("\n");
			temp_a = temp_a->next;
		}
		printf("\n");
		temp_b = stacks->stack_b;
		while (temp_b != NULL)
		{
			printf("Numero: %d", temp_b->nbr);
			printf("   Indice: %d", temp_b->index);
			printf("\n");
			temp_b = temp_b->next;
		}

		// free
		free(nbrs);
		free(stacks->stack_a);
		free(stacks->stack_b);
		free(stacks);
	}
	return (0);
}