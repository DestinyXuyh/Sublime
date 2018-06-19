#ifndef TREENODE_H
#define TREENODE_H

#define TRIE_MAX_CHAR_NUM 26

struct TrieNode
{
	TrieNode* child[TRIE_MAX_CHAR_NUM];
	bool is_end;
	TrieNode(): is_end(false) {
		for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i)
		{
			child[i] = NULL;
		}
	}
};

#endif