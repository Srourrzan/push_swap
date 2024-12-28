/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:35:41 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/28 20:00:25 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(char *src, t_list **root, char **dup_num)
{
    int     iter;
    int     number;
    int     sign;

    iter = 0;
    sign = +1;
    number = 0;
    if(src[iter] == '-' || src[iter] == '+')
    {
        if(src[iter] == '-')
            sign = -1;
        iter++;
    }
    while (src[iter])
    {
        if ((number * 10 == 2147483640 && (((src[iter] - '0') > 7 && sign == 1) 
            || ((src[iter] - '0') > 8 && sign == -1))) || number >= 214748365)
        {
            ft_free_str_array(dup_num);
            ft_exit(root, 2);
        }
        number = (number * 10) + (src[iter] - '0');
        iter++; 
    }
    number = number * sign;
    return (number);
}

void    ft_exit(t_list **root, int exit_number)
{   
    ft_putstr("Error\n");
    delete_list(root);
    exit(exit_number);
}

void    ft_init_array(char **src, int size)
{
    int     iter;

    iter = 0;
    while (iter < size)
    {
        src[iter] = NULL;
        iter++;
    }
}