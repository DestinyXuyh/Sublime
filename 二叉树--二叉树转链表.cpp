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

class Solution
{
public:
	void flatten(TreeNode* root) {
		//从root开始
		TreeNode* last = NULL;
		preorder(root, last);
	}
private:
	void preorder(TreeNode* node, TreeNode* &last)
	{
		if (!node)
			return;
		if (node->left == NULL && node->right == NULL)
		{
			/* 当处理到叶节点时 */
			last = node;
			return;
		}
		//不是叶节点
		TreeNode* left       = node->left;
		TreeNode* right      = node->right;
		TreeNode* left_last  = NULL;
		TreeNode* right_last = NULL;
		if (left)
		{
			/* 如果有左子树 */
			preorder(left, left_last);	//把左子树拉直
			node->left  = NULL;
			node->right = left;
			last        = left_last;
		}
		if (right)
		{
			/* 有右子树的话 */
			preorder(right, right_last);	//把右子树拉直
			if (left_last)
			{
				/* 如果存在左子树的尾节点 */
				left_last->left  = NULL;
				left_last->right = right;
			}
			last = right_last;
		}
	}
};

int main()
{
	Solution s;
	
	TreeNode n1(5), n2(4), n3(8), n4(11), n5(13), n6(4), n7(7), n8(2), n9(5), n10(1);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n3.left = &n5;
	n3.right = &n6;
	n4.left = &n7;
	n4.right = &n8;
	n6.left = &n9;
	n6.right = &n10;

	s.flatten(&n1);
	TreeNode* head = &n1;
	while (head) {
		/* code */
		if (head->left)
			printf("error\n");
		printf("%d ", head->value);
		head = head->right;
	}
	printf("\n");
	return 0;
}