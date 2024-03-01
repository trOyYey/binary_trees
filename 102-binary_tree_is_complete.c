#include "binary_trees.h"

/**
 * measure_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node
 * Return: the size of the measured nodes
 */

size_t measure_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);
	if (tree->left)
		size += 1 + measure_tree_size(tree->left);
	if (tree->right)
		size += 1 + measure_tree_size(tree->right);
	return (size);
}

/**
 * is_complete - function that checks if a binary tree is complete
 * @tree: pointer to the tree
 * @index: current node
 * @size: size of the tree
 * Return: 1 or 0
 */

int is_complete(const binary_tree_t *tree, int index, int size)
{
	int left = 1, right = 1;

	if (tree == NULL)
		return (0);
	if (index >= size)
		return (0);
	if (tree->left)
		left = is_complete(tree->left, index * 2 + 1, size);
	if (tree->right)
		right = is_complete(tree->right, index * 2 + 2, size);
	return (left * right);
}

/**
 * binary_tree_is_complete - main entry point
 * @tree: pointer to the root node
 * Return: 1 or 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int sz;

	if (tree == NULL)
		return (0);
	sz = measure_tree_size(tree) + 1;
	return (is_complete(tree, 0, sz));
}
