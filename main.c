/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:52 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/03 20:13:19 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		counter;
	
	counter = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	ft_fill_stack(&stack_a, argv, argc);
	counter = ft_sort_list(&stack_a, &stack_b, counter);
	printf("number of ops: %d\n", counter);
	delete_list(&stack_a);
	delete_list(&stack_b);
	return (0);
}

void	ft_sort_list(t_list **a, t_list **b)
{
	t_list	*curr;
	int	i = 0;

	curr = *a;
	while(i++ < 4) //what is the best condition?
	{
		if(curr->content > curr->next->content)
			swap(a);
		push(a, b);
		if(curr->content < curr->next->content)
			push(a, b);
		ft_display_stacks(a, b);
	}	// should we iterate through b after finishing with a, or should it be simullitansly.
	//ft_display_stacks(a, b);
}
