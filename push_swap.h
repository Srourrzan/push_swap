/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:58 by rsrour            #+#    #+#             */
/*   Updated: 2024/11/30 17:25:58 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

t_list				*create_node(int content);
void				insert_node_back(t_list **root, int content);
void				insert_node_front(t_list **root, int content);
void 	delete_node(t_list *node);
void	delete_list(t_list **root);
void ft_putchar(char ch);
int ft_atoi(char *src);
void    ft_display_stack(t_list **root, char name);
void    ft_putstr(char *src);
void    ft_display_stacks(t_list **a, t_list **b);
void    ft_fill_stack(t_list **root, char **numbers);

#endif