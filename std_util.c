/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:35:41 by rsrour            #+#    #+#             */
/*   Updated: 2024/11/28 20:03:22 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(char *src)
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
        if(src[iter] >= '0' && src[iter] <= '9')
        {
            number = (number * 10) + (src[iter] - '0');
        }
        else
            return (0); // create a condition in the call statment 
        iter++; //(len(src) > 1 && ft_atoi(src) == 0 ? "Error" : 0)
    }
    number = number * sign;
    return (number);
}