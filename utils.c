/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:14:11 by gafreire          #+#    #+#             */
/*   Updated: 2025/04/02 02:34:28 by gafreire         ###   ########.fr       */
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
            // Error letters
            if ((argv[i][z] <'0' || argv[i][z] > '9') && (argv[i][z] != '-' || argv[i][z] != '+'))
            {
                // Change this !!!!!
                printf("ERROR\n");
                exit(EXIT_FAILURE);   
            }
            // Error - +
            if ((argv[i][z] == '-'  || argv[i][z] == '+') && (argv[i][z + 1] < '0' || argv[i][z] > '9'))
            {
                // Change this !!!!!
                printf("ERROR\n");
                exit(EXIT_FAILURE); 
            }
            if (argv[i][z] != ' ' && (z == 0 || argv[i][z - 1] == ' '))
                count++;
            z++;
        }
        i++;
    }
    printf("\n"); 
    printf("Total de números: %d\n",count);
    return (count);
}
