/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:52 by rsrour            #+#    #+#             */
/*   Updated: 2024/11/30 13:52:58 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * TO DO:
 * create a function to display the actions taken by the program
 * create a function to display the stake movements
 */

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	
	if (argc == 1)
		return (0);
	stack_a = create_node(ft_atoi(argv[1]));
	stack_b = create_node(5);
	ft_display_stacks(&stack_a, &stack_b);
	/* In case of error,
		*	it must display "Error" followed by a '\n' on the standard error.
		* Errors include for example: some arguments aren't integers,
		*	some arguments are bigger
		* than an integer and/or there are duplicates.
		*/
}