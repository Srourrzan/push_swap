/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:35:41 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/22 20:02:17 by rsrour           ###   ########.fr       */
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
            if ((number * 10 == 2147483640 && (((src[iter] - '0') > 7 && sign == 1) 
                || ((src[iter] - '0') > 8 && sign == -1))) 
                || number >= 214748365)
            {
                ft_putstr("Error\n");
                exit (2);
            }
            number = (number * 10) + (src[iter] - '0');
        }
        else
            return (0); // create a condition in the call statment 
        iter++; //(len(src) > 1 && ft_atoi(src) == 0 ? "Error" : 0)
    }
    number = number * sign;
    return (number);
}