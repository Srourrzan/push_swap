/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:52 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/30 20:05:57 by rsrour           ###   ########.fr       */
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
	int			iter = 0;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	ft_fill_stack(&stack_a, argv, argc);
	printf("Is stack sorted? %d\n", ft_sort_check(&stack_a));
	if (argc > 2)
	{
		while (!ft_sort_check(&stack_a) && iter < 4)
		{
			sort_list(&stack_a, &stack_b);
			iter++;
		}
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
	t_list	*curr_a;
	t_list	*curr_b;
	t_list	*prev_b;

	curr_a = *a;
	curr_b = *b;
	if(curr_a->content > curr_a->next->content)
	{
		swap(a);
		ft_putstr("\nsa\n");
		ft_display_stacks(a, b);
	}
	push(a, b);
	ft_putstr("\npa\n");
	ft_display_stacks(a, b);
	if (curr_b->next != NULL)
	{
		if(curr_b->content < curr_b->next->content)
		{
			swap(b);
			ft_putstr("\nsb\n");
			ft_display_stacks(a, b);
		}
	}

}
