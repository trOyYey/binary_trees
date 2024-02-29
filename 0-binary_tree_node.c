#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a new binary tree node
 * @parent: pointer to the parent new node
 * @value: the value to put inside n of the new node
 * Return: pointer to new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_btree;

	new_btree = malloc(sizeof(binary_tree_t));
	if (!new_btree)
		return (NULL);
	new_btree->n = value;
	new_btree->parent = parent;
	new_btree->left = NULL;
	new_btree->right = NULL;
	return (new_btree);

}
