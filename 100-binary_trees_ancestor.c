#include "binary_trees.h"
/**
 * binary_trees_ancestor - the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: return a pointer to the lowest common ancestor , otherwise NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *tmp1, *tmp2;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first->parent == second)
		return (first->parent);
	if (second->parent == first)
		return (second->parent);
	tmp1 = first->parent;
	if (tmp1 == second)
		return (tmp1);
	tmp2 = second->parent;
	if (tmp2 == first)
		return (tmp2);
	while (tmp1)
	{
		while (tmp2)
		{
			if (tmp2 == tmp1)
				return (tmp1);
			tmp2 = tmp2->parent;
		}
		tmp1 = tmp1->parent;
		tmp2 = second->parent;
	}

	return (NULL);
}
