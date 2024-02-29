#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes in a binary tree
 * @tree: pointer to root node
 * Return: counter of nodes or 0
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		counter += binary_tree_nodes(tree->left);
	if (tree->right)
		counter += binary_tree_nodes(tree->right);
	if (tree->left != NULL || tree->right != NULL)
		counter++;
	return (counter);
}
