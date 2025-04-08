/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:26:18 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/08 05:42:48 by gafreire         ###   ########.fr       */
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

// moves
void				sa(t_stacks *stacks, int flag);
void				sb(t_stacks *stacks, int flag);
void				ss(t_stacks *stacks);
void				pa(t_stacks *stacks);
void				pb(t_stacks *stacks);
void				ra(t_stacks *stacks, int flag);
void				rb(t_stacks *stacks, int flag);
void				rr(t_stacks *stacks);
void				rra(t_stacks *stacks, int flag);
void				rrb(t_stacks *stacks, int flag);
void				rrr(t_stacks *stacks);

// create stacks
int					count_valors(char *argv[], int size);
t_stack				*start_stack(int size);
int					*add_nbrs(int argc, char **argv, int *nbrs, int nbrs_arg);
int					check_nbrs(char *nbrs);
t_stack				*add_nbrs_stack(t_stack *stack, int *nbrs, int size);

// algorithm
void				sort_stack(t_stacks *stacks, int size);
// freess
void				free_nbrs(char **nbrs);
#endif