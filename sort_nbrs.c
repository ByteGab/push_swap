/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 02:17:58 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/08 02:39:10 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stacks *stacks, int size)
{
	int i;
	int sort;
    t_stack *temp_a;

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

	if (sort == size)
		printf("Esta ordenado\n");
	else
    {
        printf("No esta ordenado\n");
        if (size == 2)
            sa(stacks,1);
        // else if (size == 3)
        //     sort_three(stacks);   
    }
}
