#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that performs a left-rotation
 *						   on a binary tree
 * @tree: pointer to the root node
 * Return: a pointer to the new root node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *post_rotate_root;

	if (!tree || !tree->right)
		return (NULL);

	post_rotate_root = tree->right;
	tree->right = post_rotate_root->left;
	post_rotate_root->left = tree;
	if (tree->right)
		tree->right->parent = tree;
	post_rotate_root->parent = tree->parent;
	tree->parent = post_rotate_root;

	if (post_rotate_root->parent != NULL)
	{
		if (post_rotate_root->parent->right == tree)
			post_rotate_root->parent->right = post_rotate_root;
		else
			post_rotate_root->parent->left = post_rotate_root;
	}
	return (post_rotate_root);
}
