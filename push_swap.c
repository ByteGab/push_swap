/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:01:00 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/01 23:13:27 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	// t_stack *stack_a;
	// t_stack *stack_b;
	int nbrs_arg;

	if (argc <= 1)
		printf("ERROR\n");
	else
	{
		// tamaño stack
		// int stack_a[] = {4, 3, 67, 8, 2};
		// int stack_b[] = {2, 1, 4, 32, 6};
		// int i = 0;

		// sa(stack_a);
		// while (i < 5)
		// {
		// 	printf("%d ", stack_a[i]);
		// 	i++;
		// }
		// //     ---------------------------------------------
		// printf("\n");
		// i = 0;
		// sb(stack_b);
		// while (i < 5)
		// {
		// 	printf("%d ", stack_b[i]);
		// 	i++;
		// }
		// //     ---------------------------------------------
		// printf("\n");
		// i = 0;
		// ss(stack_a,stack_b);
		// while (i < 5)
		// {
		// 	printf("%d ", stack_a[i]);
		// 	i++;
		// }
		// printf("\n");
		// i = 0;
		// while (i < 5)
		// {
		// 	printf("%d ", stack_b[i]);
		// 	i++;
		// }
		//     ---------------------------------------------
		// printf("\n");
		// i = 0;
		// pa(stack_a, stack_b);
		// while (i <= 5)
		// {
		// 	printf("%d ", stack_a[i]);
		// 	i++;
		// }
		// printf("\n");
		// i = 0;
		// while (i < 5)
		// {
		// 	printf("%d ", stack_b[i]);
		// 	i++;
		// }
		nbrs_arg = argc;
		printf("Numero de argumentos sin los string: %d\n",argc -1);
		count_valors(argv,nbrs_arg);
	}
	return (0);
}