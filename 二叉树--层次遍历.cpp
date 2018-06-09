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
	 * 层次遍历，不需要递归
	 * @param root [description]
	 */
	void levelOrder(TreeNode* root)
	{
		queue<TreeNode* > que;
		while(root != NULL) {
		    /* code */
		    printf("%d ", root->value);
		    if(root->left)
		    	que.push(root->left);
		    if(root->right)
		    	que.push(root->right);

		    if (que.empty())
		    {
		    	/* code */
		    	return;
		    }
		    root=que.front();
		    que.pop();
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

	s.levelOrder(&n1);
	return 0;
}