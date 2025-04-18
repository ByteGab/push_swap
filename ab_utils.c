/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 06:35:40 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/17 20:09:10 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_a(t_stacks *stacks, int nbr)
{
	int i = 0;
    t_stack *temp = stacks->stack_a;

    if (!temp) // Verifica si stack_a está vacío
        return (-1); // Devuelve -1 si la pila está vacía

    while (temp)
    {
        if (temp->nbr == nbr) // Si encuentras el número, devuelve el índice
            return (i);
        i++;
        temp = temp->next; // Avanza al siguiente nodo
    }

    return (-1); // Devuelve -1 si el número no se encuentra en stack_a
}
int	find_index_b(t_stacks *stacks, int nbr)
{
	int		i;
	t_stack	*temp;

	temp = stacks->stack_b;
	i = 0;
	
	while (temp->nbr != nbr)
	{
		i++;
		temp = temp->next;
	}
	// printf("En find index devuelve: %d\n",i);
	// stacks->stack_b->index = 0;
	return (i);
}

t_stack	*last_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		if (stack->next != NULL)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}
int	find_place_a(t_stacks *stacks, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stacks->stack_a->nbr
		&& nbr_push > last_stack(stacks->stack_a)->nbr)
		i = 0;
	else if (nbr_push > max_stack(stacks->stack_a)
		|| nbr_push < min_stack(stacks->stack_a))
		i = find_index_a(stacks, min_stack(stacks->stack_a));
	else
	{
		tmp = stacks->stack_a->next;
		while (stacks->stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stacks->stack_a = stacks->stack_a->next;
			tmp = stacks->stack_a->next;
			i++;
		}
	}
	// printf("Find place a devuelve: %d\n",i);
	return (i);
}
int	find_place_b(t_stacks *stacks, int nbr_push)
{
	int		i;
	t_stack	*tmp;
	t_stack *head;

	i = 1;
	// printf("Entrou find_place_b\n");
	if (nbr_push > stacks->stack_b->nbr
		&& nbr_push < last_stack(stacks->stack_b)->nbr)
		i = 0;
	else if (nbr_push > max_stack(stacks->stack_b)
		|| nbr_push < min_stack(stacks->stack_b))
		i = find_index_b(stacks, max_stack(stacks->stack_b));
	else
	{
		// printf("cheguei\n");
		head = stacks->stack_b;
		tmp = head->next;
		while (tmp && (head->nbr < nbr_push || tmp->nbr > nbr_push))
		{
			head = head->next;
			tmp = tmp->next;
			i++;
		}
		// printf("Acabei\n");
	}
	// printf("Devolve place_b: %d\n", i);
	return (i);
}
int	case_rrarrb(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_place_b(stacks, c))
		i = stacks->size_b - find_place_b(stacks, c);
	if ((i < (stacks->size_a - find_index_a(stacks, c))) && find_index_a(stacks,
			c))
		i = stacks->size_a - find_place_a(stacks, c);
	return (i);
}
int	case_rarrb(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_place_b(stacks, c))
		i = stacks->size_b - find_place_b(stacks, c);
	i = find_index_a(stacks, c) + i;
	// printf("Calculo rarrb: %d\n", i);
	return (i);
}
int	case_rrarb(t_stacks *stacks, int c)
{
	int	i;

	i = 0;
	ft_strlen_stack(stacks);
	if (find_index_a(stacks, c))
		i = stacks->size_a - find_index_a(stacks, c);
	i = find_place_b(stacks, c) + i;
	// printf("Calculo rrarb: %d\n", i);
	return (i);
}

int	case_rarb(t_stacks *stacks, int c)
{
	int	i;
	i = find_place_b(stacks, c);
	if (i < find_index_a(stacks, c))
		i = find_index_a(stacks, c);
	// printf("Calculo rarb: %d\n", i);
	return (i);
}
int	apply_rarb(t_stacks *stacks, int c, char s)
{
	t_stack *temp_a;
	t_stack *temp_b;

	temp_a = stacks->stack_a;
	temp_b = stacks->stack_b;
	// printf("Empeza\n");
	if (s == 'a')
	{
		// printf("Entrou na a\n");
		// printf("O numero do stack: %d\n", stacks->stack_a->nbr);
		while (temp_a->nbr != c && find_place_b(stacks, c) > 0)
		{
			rr(stacks);
			temp_a = temp_a->next;
			// printf("Fixo o rr\n");
		}
		while (temp_a->nbr != c)
		{
			ra(stacks, 1);
			// printf("Fixo o ra\n");
		}
		int place = find_place_b(stacks, c);
		while (place-- > 0)
		{
			rb(stacks, 1);
			// printf("Fixo o rb\n");
		}
		// printf("Fixoo\n");
		pb(stacks);
		// printf("Acabou a a\n");
	}
	else
	{
		while (temp_b->nbr != c && find_place_a(stacks, c) > 0)
			// change find_place
			rr(stacks);
		while (temp_b->nbr != c)
			rb(stacks, 1);
		int place_b = find_place_a(stacks, c);
		while (place_b-- > 0)
			ra(stacks, 1);
		pa(stacks);
	}
	// printf("Acaba el apply");
	return (-1);
}
int	apply_rrarrb(t_stacks *stacks, int c, char s)
{
	if (s == 'a')
	{
		while (stacks->stack_a->nbr != c && find_place_b(stacks, c > 0))
			rrr(stacks);
		while (stacks->stack_a->nbr != c)
			rra(stacks, 1);
		while (find_place_b(stacks, c) > 0)
			rrb(stacks, 1);
		pb(stacks);
	}
	else
	{
		while (stacks->stack_b->nbr != c && find_place_a(stacks, c) > 0)
			rrr(stacks);
		while (stacks->stack_b->nbr != c)
			rrb(stacks, 1);
		while (find_place_a(stacks, c) > 0)
			rra(stacks, 1);
		pa(stacks);
	}
	return (-1);
}

int	apply_rarrb(t_stacks *stacks, int c, char s)
{
	if (s == 'a')
	{
		while (stacks->stack_a->nbr != c)
			ra(stacks, 1);
		while (find_place_b(stacks, c) > 0)
			rrb(stacks, 1);
		pb(stacks);
	}
	else
	{
		while (find_place_a(stacks, c) > 0)
			ra(stacks, 1);
		while (stacks->stack_b->nbr != c)
			rrb(stacks, 1);
		pa(stacks);
	}
	return (-1);
}

int	apply_rrarb(t_stacks *stacks, int c, char s)
{
	if (s == 'a')
	{
		while (stacks->stack_a->nbr != c)
			rra(stacks, 1);
		while (find_place_b(stacks, c) > 0)
			rb(stacks, 1);
		pb(stacks);
	}
	else
	{
		while (find_place_a(stacks, c) > 0)
			rra(stacks, 1);
		while (stacks->stack_b->nbr != c)
			rb(stacks, 1);
		pa(stacks);
	}
	return (-1);
}