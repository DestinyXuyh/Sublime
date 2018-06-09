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
	/**
	 * 求两个路径上最后一个相同的节点
	 * 1. 求出较短路径的长度n
	 * 2. 同时遍历p节点和q节点的路径，最后一个发现的相同节点就是最近公共祖先
	 * @param  root [description]
	 * @param  p    [description]
	 * @param  q    [description]
	 * @return      [description]
	 */
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		std::vector<TreeNode*> path;
		std::vector<TreeNode*> resultOfp;
		std::vector<TreeNode*> resultOfq;
		int finish = 0;
		int index = -1;

		preorder(root, p, path, resultOfp, finish);
		path.clear();
		finish = 0;
		preorder(root, q, path, resultOfq, finish);
		int n = resultOfq.size() > resultOfp.size() ? resultOfp.size() : resultOfq.size();

		for (int i = 0; i < n; ++i)
		{
			/* code */
			if (resultOfq[i] != resultOfp[i])
			{
				index = i;
				break;
			}
		}

		if (index == -1)
			return NULL;
		else
			return resultOfp[index - 1];
	}
private:
	/**
	 * 求根节点至某节点的路径（深度搜索）
	 * @param node   [正在遍历的节点]
	 * @param search [待搜索的节点]
	 * @param path   [节点路径栈]
	 * @param result [路径结果]
	 * @param finish [记录是否找到节点，未找到是0，找到是1]
	 */
	void preorder(TreeNode* node, TreeNode* search, vector<TreeNode*>& path,
	              vector<TreeNode*>& result,
	              int& finish)
	{
		if (!node || finish == 1)
			return;
		path.push_back(node);
		if (node == search)
		{
			//找到的目标节点
			finish = 1;
			result = path;
		}
		preorder(node->left, search, path, result, finish);
		preorder(node->right, search, path, result, finish);
		//后序遍历完后做什么事情
		path.pop_back();
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

	TreeNode* res = s.lowestCommonAncestor(&n1, &n7, &n8);
	cout << res->value << endl;
	
	return 0;
}