#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the sibling of a node
 *
 * @node: Pointer to the node to find the uncle
 *
 * Return: return a pointer to the uncle node , otherwise NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (0);
	if (node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
