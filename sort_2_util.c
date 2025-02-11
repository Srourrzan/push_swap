/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:12:40 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/11 00:22:01 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_split_stack(t_list **stack_a, int counter, int fd)
{
    int     len;
    int     iter;
    t_list  *half;
    t_list  *prev;
    t_list  *temp;
    
    iter = 0;
    temp = *stack_a;
    half = *stack_a;
    prev = temp;
    len = len_list(stack_a);
    while(iter < (len / 2) )
    {
        temp = half;
        half = half->next;
        iter++;
    }
    temp->next = NULL;
    ft_display_stacks(&prev, &half, fd);
    counter = ft_ascend_reverse_rotate(&prev, &half, counter, fd);
	counter = ft_ascend_swap(&prev, &half, counter, fd);
    counter = ft_ascend_reverse_rotate(&prev, &half, counter, fd);
	counter = ft_ascend_swap(&prev, &half, counter, fd);
    ft_putstr("merging\n", fd);
    *stack_a = ft_merge_stack(&prev, &half, fd);
    return counter;
}

t_list     *ft_merge_stack(t_list **stack_1, t_list **stack_2, int fd)
{
    t_list  *curr_1;
    t_list  *curr_2;
    t_list  *temp;
    
    temp = *stack_1;
    curr_1 = *stack_1;
    curr_2 = *stack_2;
    while(curr_1->next != NULL)
        curr_1 = curr_1->next;
    curr_1->next = curr_2;
    *stack_1 = temp;
    ft_putstr("Displaying after merging\n", fd);
    curr_1 = *stack_1;
    while (curr_1 != NULL)
    {
		ft_putnbr(curr_1->content, fd);
		ft_putchar('\n', fd);
		curr_1 = curr_1->next;
    }
    return (*stack_1);
}
