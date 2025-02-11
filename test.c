#include "push_swap.h"

int 	ft_ascend_rr_splited_stack(t_list **head, t_list **midd, int counter, int fd)
{
	t_list		*last_a;
	t_list		*last_b;

	last_a = *a;
	if ((*b) != NULL)
	{
		last_b = *b;
		while (last_b->next != NULL)
			last_b = last_b->next;
	}
	while (last_a->next != NULL)
		last_a = last_a->next;
	while (last_a->content < (*a)->content)
	{
		if ((*b) && (last_b->content > (*b)->content))
		{
			rrr(a, b);
			ft_putstr("rrr\n", fd);
			counter++;
			ft_display_stacks(a, b, fd);
		}
		else
		{
			reverse_rotate(a);
			ft_putstr("rra\n", fd);
			counter++;
			ft_display_stacks(a, b, fd);
		}
		while (last_a->next != NULL)
			last_a = last_a->next;
		while ((*b) && last_b->next != NULL)
			last_b = last_b->next;
	}
	return counter;
}