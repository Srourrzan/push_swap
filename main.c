/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:52 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/18 20:02:57 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * TO DO:
 * create a function to display the actions taken by the program (DONE)
 * create a function to display the stake movements
 * Create a function to fill the stack with input data (DONE)
 * 
 */

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	ft_fill_stack(&stack_a, argv);
	t_list	*curr;
	curr = stack_a;
	while (curr  && (curr->next != NULL))
	{
		if((curr->content > curr->next->content))
		{
			printf("\nsa:\n-----\n");
			swap(&stack_a);
			ft_display_stack(&stack_a, 'a');
		}
		curr = curr->next;
	}
	ft_display_stack(&stack_a, 'a');
	delete_list(&stack_a);
	delete_list(&stack_b);
	/* In case of error,
		*	it must display "Error" followed by a '\n' on the standard error.
		* Errors include for example: some arguments aren't integers,
		*	some arguments are bigger
		* than an integer and/or there are duplicates.
		*/
}
