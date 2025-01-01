/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:22 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/01 17:41:56 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_list_ascend(t_list **a, t_list **b)
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

void	ft_sort_list_descend(t_list **b, t_list **a)
{
	if((*b)->content < (*b)->next->content)
	{
		swap(b);
		ft_putstr("\nsb\n");
		ft_display_stacks(a, b);
	}
	push(b, a);
	ft_putstr("\npb\n");
	ft_display_stacks(a, b);
	if ((*a)->next != NULL)
	{
		if((*a)->content > (*a)->next->content)
		{
			swap(a);
			ft_putstr("\nsa\n");
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

int	ft_descend_check(t_list **b)
{
	t_list	*curr;

	curr = *b;
	if (!curr->next)
		return (1);
	while (curr->next != NULL)
	{
		if (curr->content < curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}