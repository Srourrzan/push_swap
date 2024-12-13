#include "push_swap.h"

void    ft_display_stack(t_list **root, char name)
{
    t_list  *curr;

    curr = *root;
    while(curr != NULL)
    {
        ft_putnbr(curr->content);
        ft_putchar('\n');
        curr = curr->next;
    }
    ft_putchar('_');
    ft_putchar('\n');
    ft_putchar(name);
    ft_putchar('\n');
}

void ft_putchar(char ch)
{
    write(1, &ch, 1);
}

void    ft_putstr(char *src)
{
    int     iter = 0;

    while(src[iter])
    {
        ft_putchar(src[iter]);
        iter++;
    }
}

void    ft_display_stacks(t_list **a, t_list **b)
{
    t_list  *curr_a;
    t_list  *curr_b;

    curr_a = *a;
    curr_b = *b;
    while(curr_a != NULL || curr_b != NULL)
    {
        if (curr_a)
        {
            ft_putnbr(curr_a->content);
            curr_a = curr_a->next;
        }
        ft_putstr("          ");
        if (curr_b)
        {
            ft_putnbr(curr_b->content);
            curr_b = curr_b->next;
        }
        ft_putchar('\n');
    }
    ft_putstr("_          _");
    ft_putchar('\n');
    ft_putstr("a          b");
    ft_putchar('\n');
}

void    ft_putnbr(int  nbr)
{
    char     res;

    if (nbr < 0)
    {
        if (nbr == -2147483648)
        {
            ft_putstr("-2147483648");
            return;
        }
        ft_putchar('-');
        nbr *= -1;
    }
    if (nbr > 9)
        ft_putnbr(nbr / 10);
    res = nbr % 10 + '0';
    ft_putchar(res);
}