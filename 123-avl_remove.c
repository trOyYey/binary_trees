#include "binary_trees.h"

/**
 * avl_search - function that searches for a value in avl tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return:  pointer to the node containing the value or NULL
 */

avl_t *avl_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *) tree);
	if (value > tree->n)
	{
		if (tree->right)
			return (avl_search(tree->right, value));
		else
			return (NULL);
	}
	else
	{
		if (tree->left)
			return (avl_search(tree->left, value));
		else
			return (NULL);
	}
}

/**
 * replacing_avl - gets first in-order successor
 * @tree: tree pointer
 * @value: number to comapre to
 * @left: indicator for which side the function searches
 * Return: tree after reconstruction
 */

bst_t *replacing_avl(const avl_t *tree, int value, int left)
{
	if ((left != 0 && tree->right == NULL) ||
		(left == 0 && tree->left == NULL))
		return ((avl_t *) tree);
	if (left != 0)
		return (replacing_avl(tree->right, value, left));
	return (replacing_avl(tree->left, value, left));
}

/**
 * swapping_avl - changes position of the nodes post removal
 * @prev_node: node before removal
 * @new_avl_node: node after removal
 */

void swapping_avl(avl_t *prev_node, avl_t *new_avl_node)
{
	if (new_avl_node->parent && new_avl_node->parent->right == new_avl_node)
		new_avl_node->parent->right = NULL;
	if (new_avl_node->parent && new_avl_node->parent->left == new_avl_node)
		new_avl_node->parent->left = NULL;
	new_avl_node->parent = prev_node->parent;
	if (new_avl_node->n > prev_node->n || new_avl_node->left == NULL)
		new_avl_node->left = prev_node->left;
	if (new_avl_node->n < prev_node->n || new_avl_node->right == NULL)
		new_avl_node->right = prev_node->right;
	if (new_avl_node->right != NULL)
		new_avl_node->right->parent = new_avl_node;
	if (new_avl_node->left != NULL)
		new_avl_node->left->parent = new_avl_node;
	if (new_avl_node->parent && new_avl_node->parent->left == prev_node)
		new_avl_node->parent->left = new_avl_node;
	else if (new_avl_node->parent && new_avl_node->parent->right == prev_node)
		new_avl_node->parent->right = new_avl_node;

}


/**
 * avl_rotate_2 - dose the rotaions
 * @root: root node
 * Return: root node after rotation
 */

avl_t *avl_rotate_2(avl_t **root)
{
	int blnc_f, r_blnc_f, l_blnc_f;

	if (*root == NULL)
		return (NULL);
	if ((*root)->right != NULL)
		(*root)->right = avl_rotate_2(&(*root)->right);
	if ((*root)->left != NULL)
		(*root)->left = avl_rotate_2(&(*root)->left);
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
 * avl_remove - function that removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value:  value to remove in the tree
 * Return:  pointer to the new root node of the tree after removing
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *prev_avl, *new_avl = NULL;

	if (root == NULL)
		return (NULL);
	prev_avl = avl_search(root, value);
	if (prev_avl == NULL)
		return (NULL);
	if (prev_avl->right != NULL)
		new_avl = replacing_avl(prev_avl->right, value, 0);
	else if (prev_avl->left != NULL)
		new_avl = replacing_avl(prev_avl->left, value, 1);
	else
	{
		if (prev_avl->parent && prev_avl->parent->right == prev_avl)
			prev_avl->parent->right = NULL;
		else if (prev_avl->parent && prev_avl->parent->left == prev_avl)
			prev_avl->parent->left = NULL;
		free(prev_avl);
		return (avl_rotate_2(&root));
	}
	swapping_avl(prev_avl, new_avl);
	if (prev_avl == root)
		root = new_avl;
	free(prev_avl);
	return (avl_rotate_2(&root));
}

