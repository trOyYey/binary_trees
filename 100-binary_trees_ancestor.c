#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor or NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *holder = second;

	for (; first != NULL ; first = first->parent)
	{
		for (second = holder; second != NULL; second = second->parent)
		{
			if (first == second)
				return ((binary_tree_t *) first);
		}
	}
	return (NULL);
}
