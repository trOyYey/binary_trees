#include "binary_trees.h"

/**
 * binary_tree_preorder - function that traverse using pre-order method
 * @tree: pointer to the root
 * @func: pointer to the function to call
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || !func)
		return;
	func(tree->n);
	if (tree->left)
		binary_tree_preorder(tree->left, func);
	if (tree->right)
		binary_tree_preorder(tree->right, func);
}
