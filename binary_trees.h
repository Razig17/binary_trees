#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
#include <math.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

void binary_tree_print(const binary_tree_t *);

/**
 * binary_tree_node - Creates a binary tree node
 *
 * @parent: Pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 *
 * @parent: Pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/**
 * binary_tree_insert_right - inserts a node as the left-child of another node
 *
 * @parent: Pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/**
 * binary_tree_delete - Deletes an entire binary tree
 *
 * @tree: Pointer to the root node of the tree to delete
 *
 */
void binary_tree_delete(binary_tree_t *tree);

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 *
 * @node: Pointer to the node to check
 *
 * Return: return 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node);

/**
 * binary_tree_is_root - Checks if a node is a root
 *
 * @node: Pointer to the node to check
 *
 * Return: return 1 if node is a root, otherwise 0
 */

int binary_tree_is_root(const binary_tree_t *node);

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func:  pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func:  pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_postorder - Goes through binary tree using post-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func:  pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: returns the hight or 0 on failure
 */
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_depth - Measures the depth of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the depth
 *
 * Return: returns the depth or 0 on failure
 */
size_t binary_tree_depth(const binary_tree_t *tree);

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: returns the size or 0 on failure
 */
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 *
 * @tree: Pointer to the root node of the tree to count the leaves
 *
 * Return: returns the number of the leaves or 0 on failure
 */
size_t binary_tree_leaves(const binary_tree_t *tree);


/**
 * binary_tree_nodes - Counts the nodes in a binary tree
 *
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Return: returns the number of the nodes or 0 on failure
 */
size_t binary_tree_nodes(const binary_tree_t *tree);

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: returns the balance factor or 0 on failure
 */
size_t binary_tree_balance(const binary_tree_t *tree);

/**
 * binary_tree_is_full - Checks if a binary tree is full
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: return 0 if tree is full or on failure , otherwise 1
 */
int binary_tree_is_full(const binary_tree_t *tree);

/**
 * is_full - Checks if a binary tree is full
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: return 1 if tree is full, otherwise 0
 */
int is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * binary_tree_sibling - Finds the sibling of a node
 *
 * @node: Pointer to the node to find the sibling
 *
 * Return: return a pointer to the sibling node , otherwise NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/**
 * binary_tree_uncle - Finds the sibling of a node
 *
 * @node: Pointer to the node to find the uncle
 *
 * Return: return a pointer to the uncle node , otherwise NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/**
 * binary_trees_ancestor - the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: return a pointer to the lowest common ancestor , otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func:  pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 * 
 * Return: 1 if tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * is_complete - Checks if a binary tree is complete from a queue
 *
 * @tree: Pointer to the queue
 * @size: Size of the queue
 * Return: 1 if tree is complete, otherwise 0
 */
int is_complete(binary_tree_t **tree, size_t size);
#endif /* _BINARY_TREES_H_ */
