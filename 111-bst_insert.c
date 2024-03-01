#include "binary_trees.h"

/**
 * is_parent - gets the node to be instered under
 * @tree: tree pointer
 * @value: number to comapre to
 * Return: 1 for bst 0 other wise
 */

bst_t *is_parent(bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return (NULL);
	if (value < tree->n)
	{
		if (tree->left)
			return (is_parent(tree->left, value));
		else
			return (tree);
	}
	else
	{
		if (tree->right)
			return (is_parent(tree->right, value));
		else
			return (tree);
	}
}

/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node
 * @value: value of the node to be stored inside n
 * Return: pointer to the created node, or NULL
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		new_node = *tree;
		return (*tree);
	}

	new_node = is_parent(*tree, value);
	if (new_node == NULL)
		return (NULL);

	new_node = binary_tree_node(new_node, value);
	if (value < new_node->parent->n)
		new_node->parent->left = new_node;
	else
		new_node->parent->right = new_node;
	return (new_node);
}
