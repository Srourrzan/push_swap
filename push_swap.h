/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:58 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/01 17:20:12 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

t_list				*create_node(int content);
void				insert_node_back(t_list **root, int content);
void				insert_node_front(t_list **root, int content);
//void				delete_node(t_list *node);
void				delete_list(t_list **root);
void				ft_putchar(char ch);
void				ft_putnbr(int nbr);
void				ft_display_stack(t_list **root, char name);
void				ft_putstr(char *src);
void				ft_display_stacks(t_list **a, t_list **b);
void				ft_fill_stack(t_list **root, char **numbers, int argc);
void				swap(t_list **root);
void				ss(t_list **root_a, t_list **root_b);
void				push(t_list **src_list, t_list **dst_list);
void				rotate(t_list **root);
void				rr(t_list **root_a, t_list **root_b);
void				reverse_rotate(t_list **root);
int					ft_atoi(char *src, t_list **root, char **dup_num);
void				rrr(t_list **root_a, t_list **root_b);
int     			ft_is_number(char *src);
int     			ft_is_dup(char **dup_num, char *number);
void    ft_exit(t_list **root, char **arr, int exit_number);
int					len_list(t_list **root);
int     			ft_strcmp(const char *s1, const char *s2);
char    *ft_strdup(const char *s);
int     ft_strlen(const char *s);
void    ft_init_array(char **src, int size);
void    			ft_free_str_array(char **arr);
int					ft_ascend_check(t_list  **a);
void				sort_list(t_list **a, t_list **b);

#endif