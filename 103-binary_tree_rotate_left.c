#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: A pointer to the new root of the tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root, *old_left;

	if (tree == NULL)
		return (NULL);
	old_root = tree;
	new_root = tree->right;
	if (new_root == NULL)
		return (NULL);
	old_left = new_root->left;

	if (old_left)
		old_left->parent = old_root;
	old_root->right = old_left;
	new_root->left = old_root;
	old_root->parent = new_root;
	new_root->parent = NULL;
	return (new_root);
}
