#include "binary_trees.h"

/**
 * binary_tree_depth - function that measures the depth of a node
 * @tree: pointer to the node to measure
 * Return: depth of node or 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *temp_bt;
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	temp_bt = tree->parent;
	while (temp_bt)
	{
		depth++;
		temp_bt = temp_bt->parent;
	}
	return (depth);
}
