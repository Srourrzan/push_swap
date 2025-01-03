/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:14:19 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/03 20:38:44 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_stack(t_list **root, char name)
{
	t_list	*curr;

	curr = *root;
	while (curr != NULL)
	{
		ft_putnbr(curr->content);
		ft_putchar('\n');
		curr = curr->next;
	}
	ft_putchar('_');
	ft_putchar('\n');
	ft_putchar(name);
	ft_putchar('\n');
}

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr(char *src)
{
	int	iter;

	iter = 0;
	while (src[iter])
	{
		ft_putchar(src[iter]);
		iter++;
	}
}

void	ft_display_stacks(t_list **a, t_list **b)
{
	t_list	*curr_a;
	t_list	*curr_b;
	t_list	*temp;

	curr_a = *a;
	curr_b = *b;
	temp = curr_a;
	while (curr_a != NULL || curr_b != NULL)
	{
		if (curr_a)
		{
			ft_putnbr(curr_a->content);
			temp = curr_a;
			curr_a = curr_a->next;
		}
		ft_correct_space_display(temp);
		if (curr_b)
		{
			ft_putnbr(curr_b->content);
			curr_b = curr_b->next;
		}
		ft_putstr("\n");
	}
	ft_putstr("___________   ___________\n");
	ft_putstr("a             b\n");
}

void	ft_putnbr(int nbr)
{
	char	res;

	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	res = nbr % 10 + '0';
	ft_putchar(res);
}

void	ft_correct_space_display(t_list *node)
{
	int		len;
	int		iter;
	static int		snumber;
	int		number;
	
	len = 0;
	iter = 0;
	number = node->content;
	if (snumber != node->content || (node->next != NULL))
	{
		snumber = number;
		if (number < 0)
		{
			number = number * -1;
			len++;
		}
		while (number > 0)
		{
			number /= 10;
			len++;
		}
	}
	while (iter < (13 - len))
	{
		ft_putstr(" ");
		iter++;
	}
}
