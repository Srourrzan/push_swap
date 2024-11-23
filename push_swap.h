#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    int     content;
    struct  s_list   *next;
}       t_list;

t_list	*create_node(int content);
void insert_node_back(t_list **root, int content);

#endif