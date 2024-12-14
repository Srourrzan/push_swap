/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:02:20 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/14 15:45:49 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push function is responsible for doing the following two operations:
 *
	- pa (push a): Take the first element at the top of b and 
 *                 put it at the top of a. Do nothing if b is empty.
 *
	- pb (push b): Take the first element at the top of a and 
 *                 put it at the top of b. Do nothing if a is empty.
 */

void	push(t_list **src_list, t_list **dst_list)
{
	t_list	*temp;

	if (!src_list || !(*src_list))
		return ;
	temp = *src_list;
	*src_list = (*src_list)->next;
	temp->next = *dst_list;
	*dst_list = temp;
}
