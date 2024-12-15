/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:52 by rsrour            #+#    #+#             */
/*   Updated: 2024/12/15 12:29:31 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * TO DO:
 * create a function to display the actions taken by the program
 * create a function to display the stake movements
 * Create a function to fill the stack with input data
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
	ft_putchar('\n');
	ft_display_stacks(&stack_a, &stack_b);
	ft_putchar('\n');
	ft_putstr("pb 3 times\n---\n");
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	ft_display_stacks(&stack_a, &stack_b);
	ft_putchar('\n');
	ft_putstr("rra\n--\n");
	reverse_rotate(&stack_a);
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
