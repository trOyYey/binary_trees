#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of binary tree
 * @tree: pointer to the root of tree
 * Return: height of tree or 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_ht = 0, right_ht = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		left_ht += 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_ht += 1 + binary_tree_height(tree->right);
	return  (left_ht > right_ht ? left_ht : right_ht);
}
