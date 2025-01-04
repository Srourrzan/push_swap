/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:22 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/04 14:40:05 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_list(t_list **a, t_list **b, int counter, int fd)
{
	if(ft_ascend_check(a))
		return counter;
	while (!ft_ascend_check(a))
	{
		while (!ft_ascend_check(a))
			counter = ft_sort_list_ascend(a, b, counter,fd);
		while (!ft_descend_check(b))
			counter = ft_sort_list_descend(b, a, counter, fd);
	}
	if(ft_ascend_check(a) && ft_descend_check(b))
	{
		while ((*b) != NULL)
		{
			push(b, a);
			ft_putstr("pa\n", fd);
			counter++;
			ft_display_stacks(a, b, fd);
		}
	}
	return counter;
}

int	ft_sort_list_ascend(t_list **a, t_list **b, int counter, int fd)
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
					ft_putstr("ss\n", fd);
					counter++;
					ft_display_stacks(a, b, fd);
				}
				else
				{
					swap(a);
					ft_putstr("sa\n", fd);
					counter++;
					ft_display_stacks(a, b, fd);
				}
			}
		}
		else
		{
			swap(a);
			ft_putstr("sa\n", fd);
			counter++;
			ft_display_stacks(a, b, fd);
		}	
	}
	push(a, b);
	ft_putstr("pa\n", fd);
	counter++;
	ft_display_stacks(a, b, fd);
	if ((*b)->next != NULL)
	{
		if((*b)->content < (*b)->next->content)
		{
			if((*a)->next != NULL)
			{
				if((*a)->content > (*a)->next->content)
				{
					ss(a, b);
					ft_putstr("\nss\n", fd);
					counter++;
					ft_display_stacks(a, b, fd);
				}
				else
				{
					swap(b);
					ft_putstr("sb\n", fd);
					counter++;
					ft_display_stacks(a, b, fd);
				}
			}
			else
			{
				swap(b);
				ft_putstr("sb\n", fd);
				counter++;
				ft_display_stacks(a, b, fd);
			}
		}
	}
	return counter++;
}

int	ft_sort_list_descend(t_list **b, t_list **a, int counter, int fd)
{
	if((*b)->content < (*b)->next->content)
	{
		if ((*a)->next != NULL)
		{
			if((*a)->content > (*a)->next->content)
			{
				ss(a, b);
				ft_putstr("ss\n", fd);
				counter++;
				ft_display_stacks(a, b, fd);
			}
			else
			{
				swap(b);
				ft_putstr("sb\n", fd);
				counter++;
				ft_display_stacks(a, b, fd);
			}
		}
		else
		{
			swap(b);
			ft_putstr("sb\n", fd);
			counter++;
			ft_display_stacks(a, b, fd);
		}
	}
	push(b, a);
	ft_putstr("pb\n", fd);
	counter++;
	ft_display_stacks(a, b, fd);
	if ((*a)->next != NULL)
	{
		if((*a)->content > (*a)->next->content)
		{
			if ((*b)->content < (*b)->next->content)
			{
				ss(a, b);
				ft_putstr("ss\n", fd);
				counter++;
				ft_display_stacks(a, b, fd);
			}
			else
			{
				swap(a);
				ft_putstr("sa\n", fd);
				counter++;
				ft_display_stacks(a, b, fd);
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