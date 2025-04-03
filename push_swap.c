/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:01:00 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/03 19:31:13 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *head;
	// t_stack *stack_b;
	int nbrs_arg;
	int	*nbrs;

	if (argc <= 1)
		printf("ERROR arg\n");
	else
	{
		printf("Numero de argumentos sin los string: %d\n",argc -1);
		nbrs_arg = count_valors(argv,argc);
		// init stack
		stack_a = start_stack(nbrs_arg);
		// free stack_a
		// while (stack_a != NULL)
		// {
		// 	printf("%d\n",stack_a->nbr);
		// 	printf("%d\n",stack_a->index);
		// 	stack_a = stack_a->next;
		// }
		nbrs = (int *)malloc((nbrs_arg + 1) * sizeof(int));
		// free array nbrs
		nbrs = add_nbrs(argc,argv,nbrs,nbrs_arg);
		stack_a = add_nbrs_stack(stack_a,nbrs,nbrs_arg);
		head = stack_a;
		while (stack_a != NULL)
		{
			printf("Numero: %d",stack_a->nbr);
			printf("   Indice: %ld",stack_a->index);
			printf("\n");
			stack_a = stack_a->next;
		}
		stack_a = head;
		sa(stack_a);
		while (stack_a != NULL)
		{
			printf("Numero: %d",stack_a->nbr);
			printf("   Indice: %ld",stack_a->index);
			printf("\n");
			stack_a = stack_a->next;
		}
	}
	return (0);
}