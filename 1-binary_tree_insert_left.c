#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts node as left child of another node
 * @parent: pointer to the parent node
 * @value: the value to store in the new node
 * Return: pointer to the created node or NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_btree;

	if (!parent)
		return (NULL);

	new_btree = malloc(sizeof(binary_tree_t));
	if (!new_btree)
		return (NULL);

	new_btree->n = value;
	new_btree->parent = parent;
	new_btree->left = parent->left;
	new_btree->right = NULL;
	parent->left = new_btree;
	if (new_btree->left)
		new_btree->left->parent = new_btree;

	return (new_btree);
}
