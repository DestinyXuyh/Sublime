#include <iostream>
#include <vector>
using namespace std;


struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): value(x), left(NULL), right(NULL) {}
};

void generate(TreeNode*, vector<vector<int> >&, vector<int>&, int, int);
vector<vector<int> > pathSum(TreeNode* root, int sum)
{
	vector<vector<int> > result;
	vector<int> item;
	generate(root, result, item, sum, 0);

	return result;
}

void generate(TreeNode* root,
              vector<vector<int> >& result,
              vector<int>& item,
              int sum,
              int i)
{
	if (!root)
	{
		return;
	}
	item.push_back(root->value);
	i += root->value;
	if (i == sum)
	{
		/* code */
		result.push_back(item);
	}

	generate(root->left, result, item, sum, i);
	
	generate(root->right, result, item, sum, i);

	item.pop_back();
	i -= root->value;
}

int main(int argc, char const *argv[])
{
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

	vector<vector<int> > result;
	result = pathSum(&n1, 22);

	for (int i = 0; i < result.size(); ++i)
	{
		/* code */
		printf("[");
		for (int j = 0; j < result[i].size(); ++j)
		{
			printf("%d ", result[i][j]);
		}
		printf("]\n");
	}
	return 0;
}