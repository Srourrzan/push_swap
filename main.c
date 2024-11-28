/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:52 by rsrour            #+#    #+#             */
/*   Updated: 2024/11/28 18:23:51 by rsrour           ###   ########.fr       */
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
	
	printf("Number of args = %d,\nthe name of the program is %s\n", argc, argv[0]);
	if (argc == 1)
		return (0);
	/* In case of error,
		*	it must display "Error" followed by a '\n' on the standard error.
		* Errors include for example: some arguments aren't integers,
		*	some arguments are bigger
		* than an integer and/or there are duplicates.
		*/
}