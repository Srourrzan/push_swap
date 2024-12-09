/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:49:02 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/09 19:44:56 by rsrour           ###   ########.fr       */
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
/*
 * swap function is responsible for doing the following two operations:
 *  - sa (swap a): Swap the first 2 elements at the top of stack a.
 *  - sb (swap b): Swap the first 2 elements at the top of stack b.abort
 *      Do nothing if there is only one or no elements
 */
void   swap(t_list **root)
{
    t_list *curr;
    t_list *next;
    t_list *n_next;
    t_list *temp;

    curr = *root;
    if(curr ==  NULL || curr->next == NULL)
        return ;
    next = curr->next;
    n_next = next->next;
    temp = curr;
    curr = next;
    next = temp;
    curr->next = next;
    next->next = n_next;
    *root = curr;
}