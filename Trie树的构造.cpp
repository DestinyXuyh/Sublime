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

void preorder(TrieNode* node, int layer)
{
	for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i)
	{
		if (node->child[i])
		{
			for (int j = 0; j < layer + 1; ++j)
			{
				printf("-----");
			}
			printf("%c", 'a' + i);
			if (node->child[i]->is_end)
			{
				printf(" <end>");
			}
			printf("\n");
			preorder(node->child[i], layer + 1);
		}
	}
}

void get_all_word_from_tire(TrieNode* node, string& word, vector<string>& word_list)
{
	for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i)
	{
		if (node->child[i])
		{
			word.push_back('a' + i);
			if(node->child[i]->is_end)
			{
				word_list.push_back(word);
			}
			get_all_word_from_tire(node->child[i], word, word_list);
			word.erase(word.length() - 1, 1);
		}
	}
}

int main()
{
	TrieNode root, n1, n2, n3;
	root.child['a' - 'a'] = &n1;
	root.child['b' - 'a'] = &n2;
	root.child['e' - 'a'] = &n3;
	n3.is_end = true;

	//preorder(&root, 0);
	string word;
	vector<string> word_list;
	get_all_word_from_tire(&root, word, word_list);
	for (int i = 0; i < word_list.size(); ++i)
	{
		printf("%s\n", word_list[i].c_str());
	}
	return 0;
}