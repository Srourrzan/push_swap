/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:52 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/19 14:04:20 by codespace        ###   ########.fr       */
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
	if(((stack_a->content) > (stack_a->next->content)))
	{
		printf("\nsa:\n-----\n");
		swap(&stack_a);
	}
	ft_display_stack(&stack_a, 'a');
	printf("\npb\n-----\n");
	push(&stack_a, &stack_b);
	ft_display_stacks(&stack_a, &stack_b);
	if(((stack_a->content) > (stack_a->next->content)))
	{
		printf("\nsa:\n-----\n");
		swap(&stack_a);
	}
	ft_display_stacks(&stack_a, &stack_b);
	printf("\npb\n-----\n");
	push(&stack_a, &stack_b);
	ft_display_stacks(&stack_a, &stack_b);
	// the condition to implementn sb (swap b) is to check if the first element is less than the second element
	if(((stack_b->content) < (stack_b->next->content)))
	{
		printf("\nsb:\n-----");
		swap(&stack_b);
		ft_display_stacks(&stack_a, &stack_b);
	}
	delete_list(&stack_a);
	delete_list(&stack_b);
	/* In case of error,
		*	it must display "Error" followed by a '\n' on the standard error.
		* Errors include for example: some arguments aren't integers,
		*	some arguments are bigger
		* than an integer and/or there are duplicates.
		*/
}
