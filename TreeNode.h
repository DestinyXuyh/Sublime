#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): value(x), left(NULL), right(NULL) {}
};

#endif