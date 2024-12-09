/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:49:02 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/09 19:49:14 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * Main Push Swap RULES:
 * "push_swap" program should take as an argument the stack 'a' formatted as a list of integers.
 * The first argument should be at the top of the stack.
*/

#include "push_swap.h"

void    ft_fill_stack(t_list **root, char **numbers)
{
    int     iter;
    int     number;

    iter = 1;
    number = 0;
    printf("start filling...\n");
    while(numbers[iter] != NULL)
    {
        printf("filling ");
        number = ft_atoi(numbers[iter]);
        printf("%d\n", number);
        insert_node_back(root, number);
        iter++;
    }
    ft_display_stack(root, 'a');
}
