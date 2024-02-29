#include "binary_trees.h"

/**
 * measure_size - measures the size of a binary tree side
 * @tree: pointer to the root node
 * Return: the size of the tree side
 */

size_t measure_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);
	if (tree->left)
		size += 1 + measure_size(tree->left);
	if (tree->right)
		size += 1 + measure_size(tree->right);
	return (size);
}

/**
 * binary_tree_is_perfect - function that checks if a tree is_perfect binary
 * @tree: pointer to the root node
 * Return: 1 if perfect and 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_perfect;

	if (tree == NULL)
		return (0);
	is_perfect = 1 + measure_size(tree->left);
	is_perfect -= 1 + measure_size(tree->right);
	return (is_perfect == 0 ? 1 : 0);
}
