/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:12:40 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/08 22:25:32 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_split_stack(t_list **stack_a, t_list **stack_b, int counter, int fd)
{
    int     len;
    int     iter;
    t_list  *half;
    t_list  *prev;
    
    iter = 0;
    prev = *stack_a;
    half = *stack_a;
    len = len_list(stack_a);
    while(iter <= len / 2)
    {
        prev = half;
        half = half->next;
        iter++;
    }
    prev->next = NULL;
    ft_putstr("Is before\n", fd);
    counter = ft_ascend_reverse_rotate(stack_a, stack_b, counter, fd);
	counter = ft_ascend_swap(stack_a, stack_b, counter, fd);
    counter = ft_ascend_reverse_rotate(&half, stack_b, counter, fd);
	counter = ft_ascend_swap(&half, stack_b, counter, fd);
    ft_merge_stack(stack_a, &half, fd);
    return counter;
}

void     ft_merge_stack(t_list **stack_1, t_list **stack_2, int fd)
{
    t_list  *curr_1;
    t_list  *curr_2;
    t_list  *temp;
    t_list  *head;
    
    temp = create_node(0);
    head = temp;
    curr_1 = *stack_1;
    curr_2 = *stack_2;
    while(curr_1 && curr_2)
    {
        if (curr_1->content < curr_2->content)
        {
            head->next = curr_1;
            curr_1 = curr_1->next;
        }
        else
        {
            head->next = curr_2;
            curr_2 = curr_2->next;
        }
        head = head->next;
    }
    if(curr_1)
        head->next = curr_1;
    if(curr_2)
        head->next = curr_2;
    *stack_1 = temp->next;
    ft_display_stack(stack_1, 'a', fd);
}
