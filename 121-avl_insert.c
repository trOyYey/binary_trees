#include "binary_trees.h"


/**
 * is_parent - gets the node to be instered under
 * @tree: tree pointer
 * @value: number to comapre to
 * Return: 1 for bst 0 other wise
 */

bst_t *is_parent(bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return (NULL);
	if (value < tree->n)
	{
		if (tree->left)
			return (is_parent(tree->left, value));
		else
			return (tree);
	}
	else
	{
		if (tree->right)
			return (is_parent(tree->right, value));
		else
			return (tree);
	}
}


/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node
 * @value: value of the node to be stored inside n
 * Return: pointer to the created node, or NULL
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		new_node = *tree;
		return (*tree);
	}

	new_node = is_parent(*tree, value);
	if (new_node == NULL)
		return (NULL);

	new_node = binary_tree_node(new_node, value);
	if (value < new_node->parent->n)
		new_node->parent->left = new_node;
	else
		new_node->parent->right = new_node;
	return (new_node);
}

/**
 * avl_rotate - dose the rotaions
 * @root: root node
 * Return: root node after rotation
 */

avl_t *avl_rotate(avl_t **root)
{
	int blnc_f, r_blnc_f, l_blnc_f;

	if (*root == NULL)
		return (NULL);
	if ((*root)->right != NULL)
		(*root)->right = avl_rotate(&(*root)->right);
	if ((*root)->left != NULL)
		(*root)->left = avl_rotate(&(*root)->left);
	blnc_f = binary_tree_balance(*root);
	r_blnc_f = binary_tree_balance((*root)->right);
	l_blnc_f = binary_tree_balance((*root)->left);
	if (blnc_f > 1 && l_blnc_f == 1)
		*root = binary_tree_rotate_right(*root);
	else if (blnc_f < -1 && r_blnc_f == -1)
		*root = binary_tree_rotate_left(*root);
	else if (blnc_f < -1 && r_blnc_f == 1)
	{
		(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}
	else if (blnc_f > 1 && l_blnc_f == -1)
	{
		(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}
	return (*root);
}

/**
 * avl_insert -  function that inserts a value in an AVL Tree
 * @tree: double pointer to the root node
 * @value: value of the node to be added
 * Return: pointer to the node or NULL
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_avl;

	if (tree == NULL)
		return (NULL);
	new_avl = bst_insert(tree, value);
	if (new_avl == NULL)
		return (NULL);
	*tree = avl_rotate(tree);
	return (new_avl);
}
