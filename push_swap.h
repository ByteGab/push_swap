/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:26:18 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/04 02:03:45 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	long			index;
	struct s_stack	*next;
}					t_stack;

t_stack				*sa(t_stack *stack_a);
void				pa(int *stack_a, int *stack_b);
t_stack				*ra(t_stack *stack_a);
t_stack				*rra(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
int					count_valors(char *argv[], int size);
t_stack				*start_stack(int size);
int					*add_nbrs(int argc, char **argv, int *nbrs, int nbrs_arg);
int					check_nbrs(char **nbrs_str, char *nbrs, int *nubr);
t_stack				*add_nbrs_stack(t_stack *stack, int *nbrs, int size);

#endif