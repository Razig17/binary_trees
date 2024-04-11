#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the depth
 *
 * Return: returns the depth or 0 on failure
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *tmp;
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	tmp = tree->parent;
	if (tmp)
		depth++;
	for (; tmp; depth++)
	{
		tmp = tmp->parent;
		if (!tmp)
			break;
	}

	return (depth);
}
