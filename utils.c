/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:14:11 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/01 22:53:54 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_valors(char *argv[],int size)
{
    int i;
    int z;
    int count;

    i = 1;
    count = 0;
    while (i < size)
    {
        z = 0;
        printf("%s ",argv[i]);  
        while (argv[i][z] != '\0')
        { 
            if (argv[i][z] != ' ' && (z == 0 || argv[i][z - 1] == ' '))
                count++;
            z++;
        }
        i++;
    }
    printf("\n"); 
    printf("Total de números: %d\n",count);
    return (0);
}