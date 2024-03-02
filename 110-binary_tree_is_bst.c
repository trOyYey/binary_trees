#include "binary_trees.h"

/**
 * IS_BST - checks the left side if smaller than root,
 *			and right side if bigger than root
 * @tree: tree pointer
 * @max: pointer to maximum value n if tree is bts
 * @min: pointer to minimum value  n if tree is bts
 * Return: 1 for success and 0 for failure
 */

int IS_BST(const binary_tree_t *tree, int *min, int *max)
{
	if (tree == NULL)
		return (1);
	if ((max != NULL && tree->n >= *max) || (min != NULL && tree->n <= *min))
		return (0);
	return (IS_BST(tree->left, min, (int *) &tree->n) &&
			IS_BST(tree->right, (int *) &tree->n, max));
}

/**
 * binary_tree_is_bst - function checks if a binary tree is BST
 * @tree: pointer to the root tree
 * Return: 1 for success and 0 for failure
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (IS_BST(tree, NULL, NULL));
}
