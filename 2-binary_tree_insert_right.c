#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts node as right child
 * @parent: pointer to the node to insert
 * @value: the value to store in the new node
 * Return: a pointer to the created node or NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_btree;

	if (!parent)
		return (NULL);
	new_btree = malloc(sizeof(binary_tree_t));
	if (!new_btree)
		return (NULL);
	new_btree->parent = parent;
	new_btree->n = value;
	new_btree->left = NULL;
	new_btree->right = parent->right;
	parent->right = new_btree;
	if (new_btree->right != NULL)
		new_btree->right->parent = new_btree;

	return (new_btree);
}
