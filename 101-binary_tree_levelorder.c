#include "binary_trees.h"

/**
 * leveling_list - storing array of levels in list of lists
 * @tree: pointer to root node
 * @x: x describes level
 * @list: list to store value n
 */

void leveling_list(const binary_tree_t *tree, int x, int **list)
{
	list[x][0]++;
	list[x][list[x][0]] = tree->n;

	if (tree->left != NULL)
		leveling_list(tree->left, x + 1, list);
	if (tree->right != NULL)
		leveling_list(tree->right, x + 1, list);
}

/**
 * binary_tree_levelorder - func that goes through binary tree using
 *							level-order traversing
 * @tree: pointer to the tree
 * @func: pointer to the function to be called on each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int **level_list, i, j, h = (int) binary_tree_height(tree) + 1;

	if (tree == NULL || !func)
		return;
	/** first number in level_list contains how many numbers in the same level **/
	/** each list of list will store each n in each level **/
	level_list = malloc(sizeof(int *) * h);
	if (!level_list)
		return;
	i = 0;
	j = 1;
	while (i < h)
	{
		level_list[i] = malloc(sizeof(int) * (j + 1));
		level_list[i][0] = 0;
		i++;
		j *= 2;
	}

	leveling_list(tree, 0, level_list);
	i = 0;
	while (i < h)
	{
		for (j = 1; j <= level_list[i][0]; j++)
			func(level_list[i][j]);
		free(level_list[i]);
		i++;
	}
	free(level_list);
}

/**
 * binary_tree_height - function that measures the height of binary tree
 * @tree: pointer to the root of tree
 * Return: height of tree or 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_ht = 0, right_ht = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		left_ht += 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_ht += 1 + binary_tree_height(tree->right);
	return (left_ht > right_ht ? left_ht : right_ht);
}
