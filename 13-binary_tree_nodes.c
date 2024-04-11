#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes in a binary tree
 *
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Return: returns the number of the nodes or 0 on failure
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	binary_tree_t *right, *left;
	size_t nr = 0, nl = 0;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;

	nl += binary_tree_nodes(left);
	nr += binary_tree_nodes(right);
	if (tree->left != NULL || tree->right != NULL)
		return (1 + nr + nl);
	return (0);
}
