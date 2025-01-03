/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:22 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/03 20:05:20 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_list(t_list **a, t_list **b, int counter)
{
	while (!ft_ascend_check(a))
	{
		while (!ft_ascend_check(a))
			counter = ft_sort_list_ascend(a, b, counter);
		while (!ft_descend_check(b))
			counter = ft_sort_list_descend(b, a, counter);
	}
	if(ft_ascend_check(a) && ft_descend_check(b))
	{
		while ((*b) != NULL)
		{
			push(b, a);
			ft_putstr("pa\n");
			counter++;
			ft_display_stacks(a, b);
		}
	}
	return counter;
}

int	ft_sort_list_ascend(t_list **a, t_list **b, int counter)
{
	if((*a)->content > (*a)->next->content)
	{
		if ((*b) != NULL)
		{
			if ((*b)->next != NULL)
			{
				if((*b)->content < (*b)->next->content)
				{
					ss(a, b);
					ft_putstr("ss\n");
					counter++;
					ft_display_stacks(a, b);
				}
			}
			else
			{
				swap(a);
				ft_putstr("sa\n");
				counter++;
				ft_display_stacks(a, b);
			}
		}	
	}
	push(a, b);
	ft_putstr("pa\n");
	counter++;
	ft_display_stacks(a, b);
	if ((*b)->next != NULL)
	{
		if((*b)->content < (*b)->next->content)
		{
			if((*a)->content > (*a)->next->content)
			{
				ss(a, b);
				ft_putstr("ss\n");
				counter++;
				ft_display_stacks(a, b);
			}
			else
			{
				swap(b);
				ft_putstr("sb\n");
				counter++;
				ft_display_stacks(a, b);
			}
		}
	}
	return counter++;
}

int	ft_sort_list_descend(t_list **b, t_list **a, int counter)
{
	if((*b)->content < (*b)->next->content)
	{
		if ((*a)->next != NULL)
		{
			if((*a)->content > (*a)->next->content)
			{
				ss(a, b);
				ft_putstr("ss\n");
				counter++;
				ft_display_stacks(a, b);
			}
		}
		else
		{
			swap(b);
			ft_putstr("sb\n");
			counter++;
			ft_display_stacks(a, b);
		}
	}
	push(b, a);
	ft_putstr("pb\n");
	counter++;
	ft_display_stacks(a, b);
	if ((*a)->next != NULL)
	{
		if((*a)->content > (*a)->next->content)
		{
			if ((*b)->content < (*b)->next->content)
			{
				ss(a, b);
				ft_putstr("ss\n");
				counter++;
				ft_display_stacks(a, b);
			}
			else
			{
				swap(a);
				ft_putstr("sa\n");
				counter++;
				ft_display_stacks(a, b);
			}
		}
	}
	return counter;
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