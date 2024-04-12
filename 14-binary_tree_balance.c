#include "binary_trees.h"

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

/**
 * binary_tree_balance - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: returns the balance factor or 0 on failure
 */
size_t binary_tree_balance(const binary_tree_t *tree)
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

	return (nl - nr);
}
