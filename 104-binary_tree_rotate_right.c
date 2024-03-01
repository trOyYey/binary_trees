#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs a left-rotation
 *							 on a binary tree
 * @tree: pointer to the root node
 * Return: a pointer to the new root node
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *post_rotate_root;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	post_rotate_root = tree->left;
	tree->left = post_rotate_root->right;
	post_rotate_root->right = tree;
	if (tree->left)
		tree->left->parent = tree;
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
