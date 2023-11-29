#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * max_check - goes through a bin tree checking ropt as max value
 * @tree: pntr to the root
 * Return: 1 if all nodes are max, else 0
 **/
int max_check(const binary_tree_t *tree)
{
	int temp1 = 1, temp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		temp1 = max_check(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		temp2 = max_check(tree->right);
	}
	return (temp1 && temp2);
}
/**
 * binary_tree_is_heap - checks if a bin tree is heap
 * @tree: pntr to the node
 * Return: 1 in case BTS / else 0
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp;

	if (!tree)
		return (0);

	tmp = binary_tree_is_complete(tree);
	if (!tmp)
		return (0);
	return (max_check(tree));
}

