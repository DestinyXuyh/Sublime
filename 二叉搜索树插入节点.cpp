#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
#include "TreeNode.h"
using namespace std;

/**
 * 二叉搜索树插入节点
 * @param node        [树的根节点]
 * @param insert_node [要插入的节点]
 */
void BST_insert(TreeNode* node, TreeNode* insert_node)
{
	if (insert_node->value < node->value)
	{
		if (node->left == NULL)
		{
			node->left = insert_node;
			return;
		}
		else
			BST_insert(node->left, insert_node);
	}
	else
	{
		if (node->right == NULL)
		{
			node->right = insert_node;
			return;
		}
		else
			BST_insert(node->right, insert_node);
	}
}

bool BST_search(TreeNode* node, int value)
{
	if (node->value == value)
		return true;
	else if (value < node->value)
	{
		if (node->left)
			BST_search(node->left, value);
		else
			return false;
	}
	else if (value > node->value)
	{
		if (node->right)
			BST_search(node->right, value);
		else
			return false;
	}
}

void preorder_print(TreeNode* root, int layer)
{
	if (!root)
		return;
	for (int i = 0; i < layer; ++i)
	{
		/* code */
		printf("-----");
	}
	printf("[%d]\n", root->value);
	preorder_print(root->left, layer + 1);
	preorder_print(root->right, layer + 1);
}

int main()
{
	TreeNode root(8);
	std::vector<TreeNode* > node_vec;
	int test[] = {3, 10, 1, 6, 15};
	for (int i = 0; i < 5; ++i)
	{
		/* code */
		node_vec.push_back(new TreeNode(test[i]));
	}

	for (int i = 0; i < node_vec.size(); ++i)
	{
		/* code */
		BST_insert(&root, node_vec[i]);
	}
	preorder_print(&root, 0);

	std::vector<bool> res;
	int test1[] = {10, 3, 4, 5, 15};
	for (int i = 0; i < 5; ++i)
	{
		res.push_back(BST_search(&root, test1[i]));
	}
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << ' ';
	}

	return 0;
}