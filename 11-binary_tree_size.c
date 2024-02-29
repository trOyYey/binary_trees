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
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node
 * Return: size of tree or NULL 
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + measure_tree_size(tree));
}
