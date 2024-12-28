/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:49:02 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/28 19:54:05 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * Main Push Swap RULES:
 * "push_swap" program should take as an argument the stack 'a' formatted as a list of integers.
 * The first argument should be at the top of the stack.
*/

#include "push_swap.h"
#include <string.h>

void    ft_fill_stack(t_list **root, char **numbers, int argc)
{
    int     iter;
    int     number;
    char    **dup_num;
    int     dup_iter;

    iter = 1;
    number = 0;
    dup_iter = 0;
    dup_num = malloc(sizeof(char *) * (argc + 1));
    if (!dup_num)
        ft_exit(root, 3);
    ft_init_array(dup_num, argc + 1);
    while(numbers[iter] != NULL)
    {
        if (ft_is_number(numbers[iter]) && !ft_is_dup(dup_num, numbers[iter]))
        {
            dup_num[dup_iter] = strdup(numbers[iter]);
            if (!dup_num[dup_iter])
            {
                ft_free_str_array(dup_num);
                ft_exit(root, 3);
            }
            dup_iter++;
            number = ft_atoi(numbers[iter++], root, dup_num);
            insert_node_back(root, number);
        }
        else
        {
            ft_free_str_array(dup_num);
            ft_exit(root, 1);
        }
    }
    ft_free_str_array(dup_num);
    ft_display_stack(root, 'a');
}

// Add this helper function to free string array
void    ft_free_str_array(char **arr)
{
    int i;

    if (!arr)
        return;
    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int     ft_is_dup(char **dup_num, char *number)
{
    int     iter_arr;
    int     cmp;
    
    iter_arr = 0;
    cmp = 0;
    while(dup_num[iter_arr] != NULL)
    {
        cmp = ft_strcmp(dup_num[iter_arr], number);
        if (cmp == 0)
            return (1);
        iter_arr++;
    }
    return (0);
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
