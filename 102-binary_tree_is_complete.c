#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height, i = 0, j, size = 0, pow;
	binary_tree_t **queue;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
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
	for (i = 0; i < size; i++)
	{
		queue[i] = NULL;
	}

	queue[0] = tree->left;
	queue[1] = tree->right;
	i = 0;
	for (j = 2; j < size; j += 2)
	{
		if (queue[i])
		{
			queue[j] = queue[i]->left;
			queue[j + 1] = queue[i]->right;
		}
		i++;
	}
	return (is_complete(queue, size));
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

/**
 * is_complete - Checks if a binary tree is complete from a queue
 *
 * @tree: Pointer to the queue
 * @size: Size of the queue
 * Return: 1 if tree is complete, otherwise 0
 */
int is_complete(binary_tree_t **tree, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (tree[i] == NULL)
		{
			for (i = i + 1; i < size; i++)
			{
				if (tree[i] != NULL)
				{

					free(tree);
					return (0);
				}
				else
				{
					free(tree);
					return (1);
				}
			}
		}
	}
	free(tree);
	return (1);
}
