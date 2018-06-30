#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode
{
	int value;
	ListNode* pNext;
	ListNode(int x): value(x), pNext(NULL) {}
};
#endif