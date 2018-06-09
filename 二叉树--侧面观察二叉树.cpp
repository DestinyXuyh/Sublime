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

	std::vector<int > rightSideView(TreeNode* root)
	{
		std::vector<int> view;
		std::queue<std::pair<TreeNode*, int> > Q;	//<节点， 层数>

		if (root)
		{
			/* 根节点不为空 */
			Q.push(std::make_pair(root, 0));
		}
		while (!Q.empty()) {
			/* code */
			//取队列的头
			TreeNode* node = Q.front().first;
			int deepth     = Q.front().second;
			Q.pop();
			if (view.size() <= deepth)
			{
				view.push_back(node->value);
			}
			else
			{
				view.at(deepth) = node->value;
			}
			if (node->left)
			{
				Q.push(std::make_pair(node->left, deepth + 1));
			}
			if (node->right)
			{
				Q.push(std::make_pair(node->right, deepth + 1));
			}
		}

		return view;
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

	std::vector<int> view;
	view = s.rightSideView(&n1);
	for (int i = 0; i < view.size(); ++i)
	{
		/* code */
		printf("%d ", view[i]);
	}
	return 0;
}