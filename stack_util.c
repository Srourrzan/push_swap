/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:49:02 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/22 19:51:40 by rsrour           ###   ########.fr       */
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
    while(numbers[iter] != NULL)
    {
        if (ft_is_number(numbers[iter]))
        {
            number = ft_atoi(numbers[iter]);
            insert_node_back(root, number);
        }
        else 
        {
            ft_putstr("Error\n");
		    exit (1);
        }
        iter++;
    }
    ft_display_stack(root, 'a');
}

int     ft_is_number(char *src)
{
    int     iter;

    iter = 0;
    if (src[iter] == '+' || src[iter] == '-')
        iter++;
    while(src[iter])
    {
        if (src [iter] < '0' || src[iter] > '9')
            return (0);
        iter++;
    }
    return (1);
}