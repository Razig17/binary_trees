#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through binary tree using post-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func:  pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *right, *left;

	if (tree == NULL || func == NULL)
		return;

	left = tree->left;
	right = tree->right;

	binary_tree_postorder(left, func);
	binary_tree_postorder(right, func);
	func(tree->n);
}
