#include "binary_trees.h"

/**
 * bst_search - function that searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return:  pointer to the node containing the value or NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *) tree);
	if (value > tree->n)
	{
		if (tree->right)
			return (bst_search(tree->right, value));
		else
			return (NULL);
	}
	else
	{
		if (tree->left)
			return (bst_search(tree->left, value));
		else
			return (NULL);
	}
}

/**
 * replacing - gets first in-order successor
 * @tree: tree pointer
 * @value: number to comapre to
 * @left: indicator for which side the function searches
 * Return: tree after reconstruction
 */

bst_t *replacing(const bst_t *tree, int value, int left)
{
	if ((left != 0 && tree->right == NULL) ||
		(left == 0 && tree->left == NULL))
		return ((bst_t *) tree);
	if (left != 0)
		return (replacing(tree->right, value, left));
	return (replacing(tree->left, value, left));
}

/**
 * swapping - changes position of the nodes post removal
 * @prev_node: node before removal
 * @new_node: node after removal
 */

void swapping(bst_t *prev_node, bst_t *new_node)
{
	if (new_node->parent && new_node->parent->right == new_node)
		new_node->parent->right = NULL;
	if (new_node->parent && new_node->parent->left == new_node)
		new_node->parent->left = NULL;
	new_node->parent = prev_node->parent;
	if (new_node->n > prev_node->n || new_node->left == NULL)
		new_node->left = prev_node->left;
	if (new_node->n < prev_node->n || new_node->right == NULL)
		new_node->right = prev_node->right;
	if (new_node->right)
		new_node->right->parent = new_node;
	if (new_node->left)
		new_node->left->parent = new_node;
	if (new_node->parent && new_node->parent->left == prev_node)
		new_node->parent->left = new_node;
	else if (new_node->parent && new_node->parent->right == prev_node)
		new_node->parent->right = new_node;

}

/**
 * bst_remove - function that removes a node from a Binary Search Tree
 * @root:  pointer to the root node of the tree
 * @value: value to remove in the tree
 * Return: root of tree or null
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *prev_node, *new_node = NULL;

	if (root == NULL)
		return (NULL);
	prev_node = bst_search(root, value);
	if (prev_node == NULL)
		return (NULL);
	if (prev_node->right != NULL)
		new_node = replacing(prev_node->right, value, 0);
	else if (prev_node->left)
		new_node = replacing(prev_node->left, value, 1);
	else
	{
		if (prev_node->parent && prev_node->parent->right == prev_node)
			prev_node->parent->right = NULL;
		else if (prev_node->parent && prev_node->parent->left == prev_node)
			prev_node->parent->left = NULL;
		free(prev_node);
		return (root == prev_node ? NULL : root);
	}
	swapping(prev_node, new_node);
	free(prev_node);
	return (!new_node->parent ? new_node : root);
}
