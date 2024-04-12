#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((tree->left == NULL && tree->right != NULL) ||
	    (tree->left != NULL && tree->right == NULL))
		return (0);
	if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
		return (0);
	if (tree->left != NULL && tree->right != NULL)
	{
		return (binary_tree_is_perfect(tree->left) &&
		       binary_tree_is_perfect(tree->right));
	}

	return (1);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: returns the height or 0 on failure
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	binary_tree_t *right, *left;
	size_t nr = 0, nl = 0;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;
	if (right)
		nr++;
	if (left)
		nl++;
	nl += binary_tree_height(left);
	nr += binary_tree_height(right);
	if (nr > nl)
		return (nr);
	else
		return (nl);
}
