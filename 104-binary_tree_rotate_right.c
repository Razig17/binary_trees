#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: A pointer to the new root of the tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root, *old_right;

	if (tree == NULL)
		return (NULL);
	old_root = tree;
	new_root = tree->left;
	if (new_root == NULL)
		return (NULL);
	old_right = new_root->right;

	if (old_right)
		old_right->parent = old_root;
	old_root->left = old_right;
	new_root->right = old_root;
	old_root->parent = new_root;
	new_root->parent = NULL;
	return (new_root);
}
