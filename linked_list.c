#include "push_swap.h"

t_list	*create_node(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list *root;

	root = create_node(15);
	// root.next = malloc(sizeof(t_list));
	// root.next->content = 2;
	// root.next->next = malloc(sizeof(t_list));
	// root.next->next->content = 23;
	// root.next->next->next = NULL;

	t_list *curr = root;

	while (curr != NULL)
	{
		printf("Node value: %d\n", curr->content);
		curr = curr->next;
	}

	// free(root.next->next);
	// free(root.next);
	free(root);
	return (0);
}