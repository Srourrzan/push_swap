#include "push_swap.h"

int 	ft_ascend_rr_splited_stack(t_list **head, t_list **midd, int counter, int fd)
{
	t_list		*last_a;
	t_list		*last_b;
	t_status	*status;

	last_a = *head;
	if ((*midd) != NULL)
	{
		last_b = *midd;
		while (last_b->next != NULL)
			last_b = last_b->next;
	}
	while (last_a->next != NULL)
		last_a = last_a->next;
	status->status_1 = last_a->content < (*head)->content;
	status->status_2 = (*midd) && (last_b->content < (*midd)->content);
	while (status->status_1 || status->status_2)
	{
		if (status->status_1 && status->status_2)
		{
			rrr(head, midd);
			ft_putstr("rrr\n", fd);
		}
		else if (status->status_1)
		{
			reverse_rotate(head);
			ft_putstr("rra\n", fd);
		}
		else
		{
			reverse_rotate(midd);
			ft_putstr("rra\n", fd);
		}
		counter++;
		ft_display_stacks(head, midd, fd);
		while (last_a->next != NULL)
			last_a = last_a->next;
		while ((*midd) && last_b->next != NULL)
			last_b = last_b->next;
		status->status_1 = last_a->content < (*head)->content;
		status->status_2 = (*midd) && (last_b->content < (*midd)->content);
	}
	return counter;
}

int    ft_ascend_swap_splitted_stack(t_list **head, t_list **midd, int counter, int fd)
{
	t_status	*status;


    if(((*a)->next != NULL) && ((*a)->content > (*a)->next->content))
	{
		if ((*b) != NULL)
		{
			if ((*b)->next != NULL)
			{
				if((*b)->content < (*b)->next->content)
				{
					ss(a, b);
					ft_putstr("ss\n", fd);
					counter++;
					ft_display_stacks(a, b, fd);
				}
				else
				{
					swap(a);
					ft_putstr("sa\n", fd);
					counter++;
					ft_display_stacks(a, b, fd);
				}
			}
		}
		else
		{
			swap(a);
			ft_putstr("sa\n", fd);
			counter++;
			ft_display_stacks(a, b, fd);
		}	
	}
	return counter;
}
