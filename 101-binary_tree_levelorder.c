#include "binary_trees.h"
/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func:  pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i = 0, j, size = 0, pow;
	binary_tree_t **queue;

	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	if (tree->left == NULL && tree->right == NULL)
		return;
	height = binary_tree_height((tree));
	while (height > 0)
	{
		pow = 1;
		for (i = height; i > 0; i--)
			pow *= 2;
		size += pow;
		height--;
	}
	queue = calloc(size, sizeof(binary_tree_t));
	queue[0] = tree->left;
	queue[1] = tree->right;
	for (j = 2; j < size; j += 2)
	{
		if (queue[i])
		{
			queue[j] = queue[i]->left;
			queue[j + 1] = queue[i]->right;
		}
		i++;
	}
	for (i = 0; i < size; i++)
	{
		if (queue[i])
			func(queue[i]->n);
	}
	free(queue);
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
