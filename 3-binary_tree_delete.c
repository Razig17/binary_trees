#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 *
 * @tree: Pointer to the root node of the tree to delete
 *
 */

void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *right, *left;

	if (tree == NULL)
		return;

	right = tree->right;
	left = tree->left;

	binary_tree_delete(right);
	binary_tree_delete(left);
	free(tree);
}
