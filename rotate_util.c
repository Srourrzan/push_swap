/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:35:36 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/14 16:01:28 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate function is responsible for doing the following two operations:
 * - ra (rotate a): Shift up all elements of stack a by 1.
 *                  The first element becomes the last one.
 * - rb (rotate b): Shift up all elements of stack b by 1.
 *                  The first element becomes the last one.
 */

void    rotate(t_list **root)
{
    t_list      *temp;
    t_list      *curr;

    if (!root || !(*root) || !((*root)->next))
        return;
    curr = *root;
    temp = *root;
    *root = (*root)->next;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    temp->next = NULL;
}

/* rr: ra and rb at the same time */

void    rr(t_list **root_a, t_list **root_b)
{
    rotate(root_a);
    rotate(root_b);
}