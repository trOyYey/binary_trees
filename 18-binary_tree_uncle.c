#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of a node
 * @node: pointer to the node to find it's uncle
 * Return: pointer to the uncle or NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent
		  || !node->parent->parent->left
		  || !node->parent->parent->right)
		return (NULL);

	if (!node->parent->parent->left || !node->parent->parent->right)
		return (NULL);

	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
