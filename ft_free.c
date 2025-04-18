/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 00:27:38 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/08 00:32:15 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void    free_nbrs(char **nbrs)
{
    int i;

    i = 0;
    while ((nbrs[i] != NULL))
    {
        free(nbrs[i]);
        i++;
    }
    free(nbrs);
}