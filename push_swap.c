/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:01:00 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/05 23:52:25 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack *temp_a;
	t_stack *temp_b;
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
		nbrs = (int *)malloc((nbrs_arg + 1) * sizeof(int));
		// free array nbrs
		nbrs = add_nbrs(argc, argv, nbrs, nbrs_arg);
		stacks->stack_a = add_nbrs_stack(stacks->stack_a, nbrs, nbrs_arg);
		// ---------------------------------------------
		// prueba sa
		sa(stacks, 1);
		temp_a = stacks->stack_a;
		while (temp_a != NULL)
		{
			printf("Numero: %d", temp_a->nbr);
			printf("   Indice: %ld", temp_a->index);
			printf("\n");
			temp_a = temp_a->next;
		}
		// prueba sb
		sb(stacks, 1);
		temp_b = stacks->stack_b;
		while (temp_b != NULL)
		{
			printf("Numero: %d", temp_b->nbr);
			printf("   Indice: %ld", temp_b->index);
			printf("\n");
			temp_b = temp_b->next;
		}
		// prueba ss
		// ss(stacks);
		// ---------------------------------------------
		// prueba pb
		pb(stacks);
		temp_a = stacks->stack_a;
		while (temp_a != NULL)
		{
			printf("Numero: %d", temp_a->nbr);
			printf("   Indice: %ld", temp_a->index);
			printf("\n");
			temp_a = temp_a->next;
		}
		printf("\n");
		temp_b = stacks->stack_b;
		while (temp_b != NULL)
		{
			printf("Numero: %d", temp_b->nbr);
			printf("   Indice: %ld", temp_b->index);
			printf("\n");
			temp_b = temp_b->next;
		}
		// prueba pa
		pa(stacks);
		temp_a = stacks->stack_a;
		while (temp_a != NULL)
		{
			printf("Numero: %d", temp_a->nbr);
			printf("   Indice: %ld", temp_a->index);
			printf("\n");
			temp_a = temp_a->next;
		}
		printf("\n");
		temp_b = stacks->stack_b;
		while (temp_b != NULL)
		{
			printf("Numero: %d", temp_b->nbr);
			printf("   Indice: %ld", temp_b->index);
			printf("\n");
			temp_b = temp_b->next;
		}
		pb(stacks);
		pb(stacks);
		// prueba ra
		ra(stacks, 1);
		temp_a = stacks->stack_a;
		while (stacks->stack_a != NULL)
		{
			printf("Numero: %d", stacks->stack_a->nbr);
			printf("   Indice: %ld", stacks->stack_a->index);
			printf("\n");
			stacks->stack_a = stacks->stack_a->next;
		}
		// prueba rb
		rb(stacks,1);
		temp_b = stacks->stack_b;
		while (temp_b != NULL)
		{
			printf("Numero: %d", temp_b->nbr);
			printf("   Indice: %ld", temp_b->index);
			printf("\n");
			temp_b = temp_b->next;
		}
		printf("hola\n");
		temp_a = stacks->stack_a;
		while (stacks->stack_a != NULL)
		{
			printf("Numero: %d", stacks->stack_a->nbr);
			printf("   Indice: %ld", stacks->stack_a->index);
			printf("\n");
			stacks->stack_a = stacks->stack_a->next;
		}
		// prueba rr
		rr(stacks);
		temp_a = stacks->stack_a;
		while (stacks->stack_a != NULL)
		{
			printf("Numero: %d", stacks->stack_a->nbr);
			printf("   Indice: %ld", stacks->stack_a->index);
			printf("\n");
			stacks->stack_a = stacks->stack_a->next;
		}
		temp_b = stacks->stack_b;
		while (temp_b != NULL)
		{
			printf("Numero: %d", temp_b->nbr);
			printf("   Indice: %ld", temp_b->index);
			printf("\n");
			temp_b = temp_b->next;
		}
		exit(0);
		// prueba rb

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