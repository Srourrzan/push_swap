/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:22 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/11 00:09:43 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_list(t_list **a, t_list **b, int counter, int fd)
{
	int		push_count = 0;

	if(ft_ascend_check(a))
		return counter;
	while (!ft_ascend_check(a))
	{
		while (!ft_ascend_check(a))
		{
			counter = ft_sort_list_ascend(a, b, counter,fd);
			push_count++;
		}
		while (!ft_descend_check(b))
		{
			counter = ft_sort_list_descend(b, a, counter, fd);
			push_count++;
		}
		while ((*b) != NULL)
		{
			push(b, a);
			ft_putstr("pa\n", fd);
			counter++;
			ft_display_stacks(a, b, fd);
			push_count++;
		}
	}
	ft_putstr("pushs: ", fd+1);
	ft_putnbr(push_count, fd+1);
	return counter;
}

int	ft_sort_list_ascend(t_list **a, t_list **b, int counter, int fd)
{
	ft_putstr("Splitting===================\n", fd);
	counter = ft_split_stack(a, counter, fd);
	ft_putstr("Merged back=================\n", fd);
	ft_display_stacks(a, b, fd);
	counter = ft_ascend_reverse_rotate(a, b, counter, fd);
	counter = ft_ascend_swap(a, b, counter, fd);
	if (!ft_ascend_check(a))
	{
		counter = ft_ascend_push(a, b, counter, fd);
		counter = ft_decscend_swap(a, b, counter, fd);
	}
	return counter;
}

int	ft_sort_list_descend(t_list **b, t_list **a, int counter, int fd)
{
	if (*b)
	{
		counter = ft_dascend_rotate(a, b, counter, fd);
		counter = ft_decscend_swap(a, b, counter, fd);
		counter = ft_descend_push(a, b, counter, fd);
		counter = ft_ascend_swap(a, b, counter, fd);
	}
	return counter;
}

int	ft_ascend_check(t_list **a)
{
	t_list	*curr;

	curr = *a;
	if (curr == NULL )
		return (1);
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
	if (curr == NULL )
		return (1);
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
