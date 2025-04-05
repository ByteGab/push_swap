/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:26:18 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/05 22:04:38 by gafreire         ###   ########.fr       */
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

typedef struct s_stacks
{
	t_stack			*stack_a;
	int				size_a;
	t_stack			*stack_b;
	int				size_b;
}					t_stacks;

void				sa(t_stacks *stacks, int flag);
void				sb(t_stacks *stacks, int flag);
void				ss(t_stacks *stacks);
void				pa(t_stacks *stacks);
void				pb(t_stacks *stacks);



void				ra(t_stacks *stacks, int flag);
void				rb(t_stacks *stacks, int flag);
void				rr(t_stacks *stacks);
int					count_valors(char *argv[], int size);
t_stack				*start_stack(int size);
int					*add_nbrs(int argc, char **argv, int *nbrs, int nbrs_arg);
int					check_nbrs(char **nbrs_str, char *nbrs, int *nubr);
t_stack				*add_nbrs_stack(t_stack *stack, int *nbrs, int size);

#endif