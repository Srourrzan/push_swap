/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:35:41 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/27 23:36:05 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(char *src, t_list **root)
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
            ft_exit(root, 2);
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

void    ft_bzero(void *src, size_t n)
{
    size_t  iter;
    
    iter = 0;
    while (iter < n)
    {
        ((unsigned char *)src)[iter] = '1';
        iter++;
    }
    ((unsigned char *)src)[iter] = '\0';
}

int main()
{
    char *src;

    src = malloc(sizeof(char *)*5);
    if(!src)
        return(1);
    ft_bzero(src, 5);
    printf("%s\n", src);
    free(src);
    return (0);
}