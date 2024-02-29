#include "binary_trees.h"

/**
 * tree_height - function that measures the height of binary tree
 * @tree: pointer to the root of tree
 * Return: height of tree or 0
 */

size_t tree_height(const binary_tree_t *tree)
{
	size_t left_ht = 0, right_ht = 0;

	if (tree == NULL)
		return (-1);
	if (tree->left)
		left_ht += 1 + tree_height(tree->left);
	if (tree->right)
		right_ht += 1 + tree_height(tree->right);
	return (left_ht > right_ht ? left_ht : right_ht);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node
 * Return: balance factor or 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_height(tree->left) - tree_height(tree->right));
}
