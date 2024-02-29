#include "binary_trees.h"


/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: pointer to the root node
 * Return: 1 if full , else 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = 1;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		is_full *= binary_tree_is_full(tree->left);
	if (tree->right != NULL)
		is_full *= binary_tree_is_full(tree->right);
	if ((tree->left && tree->right) || (!tree->left && !tree->right))
		return (is_full);
	else
		return (0);
}
