/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:49:40 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/09 19:50:08 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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