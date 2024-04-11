#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the left-child of another node
 *
 * @parent: Pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;

	if (parent->right != NULL)
	{
		new->right = parent->right;
		new->right->parent = new;
	}

	parent->right = new;
	return (new);
}
