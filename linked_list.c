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

void	insert_node_back(t_list **root, int content)
{
	t_list	*node;
	t_list	*currt;

	node = create_node(content);
	if (!*root)
	{
		*root = node;
		return ;
	}
	currt = *root;
	while (currt->next != NULL)
		currt = currt->next;
	currt->next = node;
}

int	main(void)
{
	t_list *root;

	root = create_node(15);
	insert_node_back(&root, 56);
	insert_node_back(&root, 9);
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

	free(root->next->next);
	free(root->next);
	free(root);
	return (0);
}