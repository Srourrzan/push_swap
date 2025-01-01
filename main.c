/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:52 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/01 17:20:50 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * TO DO:
 * create a function to display the actions taken by the program (DONE)
 * create a function to display the stake movements
 * Create a function to fill the stack with input data (DONE)
 * Add a value check to check if the entered value is a number or not.
 * Add a duplicate checker to check if their are any duplicated values.
 */

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	//int			iter = 0;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	ft_fill_stack(&stack_a, argv, argc);
	printf("Is stack sorted in ascending? %d\n", ft_ascend_check(&stack_a));
	if (argc > 2)
	{
		while (!ft_ascend_check(&stack_a))
			sort_list(&stack_a, &stack_b);
	}
	delete_list(&stack_a);
	delete_list(&stack_b);
	/* In case of error,
		*	it must display "Error" followed by a '\n' on the standard error.
		* Errors include for example: some arguments aren't integers,
		*	some arguments are bigger
		* than an integer and/or there are duplicates.
		*/
	return (0);
}

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
