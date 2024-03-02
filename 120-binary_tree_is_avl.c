#include "binary_trees.h"

/**
 * IS_BTS - checks the left side if smaller than root,
 *			and right side if bigger than root
 * @tree: tree pointer
 * @max: pointer to maximum value n if tree is bts
 * @min: pointer to minimum value  n if tree is bts
 * Return: 1 for success and 0 for failure
 */

int IS_BST(const binary_tree_t *tree, int *min, int *max)
{
	if (tree == NULL)
		return (1);
	if ((max != NULL && tree->n >= *max) || (min != NULL && tree->n <= *min))
		return (0);
	return (IS_BST(tree->left, min, (int *) &tree->n) &&
			IS_BST(tree->right, (int *) &tree->n, max));
}

/**
 * tree_height - function that measures the height of binary tree
 * @tree: pointer to the root of tree
 * Return: height of tree or 0
 */

size_t tree_height(const binary_tree_t *tree)
{
	size_t left_ht = 0, right_ht = 0;

	if (tree == NULL)
		return (-1);
	if (tree->left)
		left_ht += 1 + tree_height(tree->left);
	if (tree->right)
		right_ht += 1 + tree_height(tree->right);
	return (left_ht > right_ht ? left_ht : right_ht);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node
 * Return: balance factor or 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (tree_height(tree->left) - tree_height(tree->right));
}

/**
 * is_avl - Main function that checks avl parameters
 * @tree: pointer to root node of the tree
 * Return: 1 if not different
 */

int is_avl(const binary_tree_t *tree)
{
	int gap;

	if (tree == NULL)
		return (1);
	gap = binary_tree_balance(tree);
	if (gap >= -1 && gap <= 1)
		gap = 1;
	else
		gap = 0;
	if (tree->right != NULL)
		gap *= is_avl(tree->right);
	if (tree->left != NULL)
		gap *= is_avl(tree->left);
	return (gap);
}

/**
 * binary_tree_is_avl - function that checks if binary tree is valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bst_val;
	int avl_val;

	if (tree == NULL)
		return (0);
	bst_val = IS_BST(tree, NULL, NULL);
	avl_val = is_avl(tree);
	return (bst_val * avl_val);
}
