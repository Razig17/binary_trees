#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: returns the size or 0 on failure
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	binary_tree_t *right, *left;
	size_t nr = 0, nl = 0;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;

	nl += binary_tree_size(left);
	nr += binary_tree_size(right);
	return (nr + nl + 1);
}
