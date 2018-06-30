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
#include "TrieNode.h"
using namespace std;

/**
 * 前序遍历
 * @param root  [description]
 * @param layer [description]
 */
void preorder_trie(TrieNode* root, int layer)
{
	for (int i = 0; i < 26; ++i)
	{
		if (root->child[i])
		{
			for (int j = 0; j < layer + 1; ++j)
			{
				printf("-----");
			}
			printf("%c", 'a' + i);
			if(root->child[i]->is_end == true)
			{
				printf("(end)");
			}
			printf("\n");
			preorder_trie(root->child[i], layer + 1);
		}

	}
}

int main(int argc, char * argv[])
{
	TrieNode root, n1, n2 , n3;
	root.child['a' - 'a'] = &n1;
	root.child['b' - 'a'] = &n2;
	root.child['c' - 'a'] = &n3;
	n2.is_end = true;

	preorder_trie(&root, 0);


	return 0;
}