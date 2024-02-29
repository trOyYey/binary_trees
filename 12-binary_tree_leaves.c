#include "binary_trees.h"

/**
 * binary_tree_leaves - function counts the leaves in a binary tree
 * @tree: pointer to root node to count it's leaves
 * Return: counter of leaves or 0
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		counter += binary_tree_leaves(tree->left);
	if (tree->right)
		counter += binary_tree_leaves(tree->right);
	if (tree->left == NULL && tree->right == NULL)
		counter++;
	return (counter);
}
