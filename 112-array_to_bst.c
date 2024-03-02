#include "binary_trees.h"

/**
 * array_to_bst - function that builds a Binary Search Tree from an array
 * @array: pointer to array
 * @size: number of element in the array
 * Return: pointer to the root node of the created BST
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root_node = NULL;
	size_t i;

	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		bst_insert(&root_node, array[i]);
		i++;
	}
	return (root_node);
}
