/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:22 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/01 17:27:04 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list **a, t_list **b)
{
	if((*a)->content > (*a)->next->content)
	{
		swap(a);
		ft_putstr("\nsa\n");
		ft_display_stacks(a, b);
	}
	push(a, b);
	ft_putstr("\npa\n");
	ft_display_stacks(a, b);
	if ((*b)->next != NULL)
	{
		if((*b)->content < (*b)->next->content)
		{
			swap(b);
			ft_putstr("\nsb\n");
			ft_display_stacks(a, b);
		}
	}
}

int	ft_ascend_check(t_list **a)
{
	t_list	*curr;

	curr = *a;
	if (!curr->next)
		return (1);
	while (curr->next != NULL)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}
