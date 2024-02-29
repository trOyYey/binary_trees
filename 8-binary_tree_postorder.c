#include "binary_trees.h"

/**
 * binary_tree_postorder - function traverse tree using post-order method
 * @tree: pointer to the root
 * @func: pointer to the function to call
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || !func)
		return;
	if (tree->left)
		binary_tree_postorder(tree->left, func);
	if (tree->right)
		binary_tree_postorder(tree->right, func);
	func(tree->n);
}
