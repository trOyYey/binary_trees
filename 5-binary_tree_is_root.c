#include "binary_trees.h"

/**
 * binary_tree_is_root - function that checks if a node is root
 * @node: pointer to the node to check
 * Return: 1 if node is the root, or NULL if not
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->parent)
		return (0);
	return (1);
}
