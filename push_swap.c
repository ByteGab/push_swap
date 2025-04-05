/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:01:00 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/05 02:07:27 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack *head;
	t_stack *head_b;
	t_stacks *stacks;
	int nbrs_arg;
	int lon;
	int *nbrs;

	lon = 0;
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
	{
		printf("Error al reservar memoria para stacks\n");
		return (1);
	}
	if (argc <= 1)
		printf("ERROR arg\n");
	else
	{
		printf("Numero de argumentos sin los string: %d\n", argc - 1);
		nbrs_arg = count_valors(argv, argc);
		// init stack
		stacks->stack_a = start_stack(nbrs_arg);
		stacks->stack_b = start_stack(0);
		// free stack_a
		// while (stack_b != NULL)
		// {
		// 	printf("%d\n",stack_b->nbr);
		// 	printf("%ld\n",stack_b->index);
		// 	stack_b = stack_b->next;
		// }
		nbrs = (int *)malloc((nbrs_arg + 1) * sizeof(int));
		// free array nbrs
		nbrs = add_nbrs(argc, argv, nbrs, nbrs_arg);
		stacks->stack_a = add_nbrs_stack(stacks->stack_a, nbrs, nbrs_arg);
		head = stacks->stack_a;
		head_b = stacks->stack_b;
		// while (stack_a != NULL)
		// {
		// 	printf("Numero: %d", stack_a->nbr);
		// 	printf("   Indice: %ld", stack_a->index);
		// 	printf("\n");
		// 	lon++;
		// 	stack_a = stack_a->next;
		// }
		// // ---------------------------------------------
		// stack_a = head;
		// prueba sa
		sa(stacks, 1); 
		head = stacks->stack_a;
		while (stacks->stack_a != NULL)
		{
			printf("Numero: %d", stacks->stack_a->nbr);
			printf("   Indice: %ld", stacks->stack_a->index);
			printf("\n");
			stacks->stack_a = stacks->stack_a->next;
		}
		sb(stacks, 1);
		while (stacks->stack_b != NULL)
		{
			printf("Numero: %d", stacks->stack_b->nbr);
			printf("   Indice: %ld", stacks->stack_b->index);
			printf("\n");
			stacks->stack_b = stacks->stack_b->next;
		}
		// // prueba ss
		ss(stacks);
		// // prueba ra
		ra(stacks);
		
		while (stacks->stack_a != NULL)
		{
			printf("Numero: %d", stacks->stack_a->nbr);
			printf("   Indice: %ld", stacks->stack_a->index);
			printf("\n");
			stacks->stack_a = stacks->stack_a->next;
		}
		exit(0);
		// stack_a = head;
		// // prueba rra
		// stack_a = rra(stack_a);
		// head = stack_a;
		// while (stack_a != NULL)
		// {
		// 	printf("Numero: %d", stack_a->nbr);
		// 	printf("   Indice: %ld", stack_a->index);
		// 	printf("\n");
		// 	stack_a = stack_a->next;
		// }

		// // prueba sb
		// stack_b = sb(stack_b, 1);
		// head_b = stack_b;
		// while (stack_b != NULL)
		// {
		// 	printf("Numero: %d", stack_b->nbr);
		// 	printf("   Indice: %ld", stack_b->index);
		// 	printf("\n");
		// 	stack_b = stack_b->next;
		// }
		// stack_a = head;
		// stacks->stack_a = stack_a;
		// while (stacks->stack_a != NULL)
		// {
		// 	printf("Numero: %d", stacks->stack_a->nbr);
		// 	printf("   Indice: %ld", stacks->stack_a->index);
		// 	printf("\n");
		// 	stacks->stack_a = stacks->stack_a->next;
		// }
	}
	return (0);
}