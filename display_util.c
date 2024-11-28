#include "push_swap.h"

void    ft_display_stack(t_list **root, char name)
{
    t_list  *curr;

    curr = *root;
    while(curr != NULL)
    {
        ft_putchar(curr->content + '0');
        ft_putchar('\n');
        curr = curr->next;
    }
    ft_putchar('_');
    ft_putchar('\n');
    ft_putchar(name);
}