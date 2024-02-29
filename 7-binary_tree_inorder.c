#include "binary_trees.h"

/**
 * binary_tree_inorder - function that traverse using in-order
 * @tree: pointer to the root
 * @func: pointer to the function to call
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || !func)
		return;
	if (tree->left)
		binary_tree_inorder(tree->left, func);
	func(tree->n);
	if (tree->right)
		binary_tree_inorder(tree->right, func);
}
