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
#include "ListNode.h"
using namespace std;

class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		//用双头指针
		ListNode* new_head = NULL;
		while (head) {
			//备份head的下一个节点的指针
			ListNode* tmp = head->pNext;
			head->pNext = new_head;
			new_head = head;
			head = tmp;
		}
		return new_head;
	}

	void printList(ListNode* head)
	{
		while (head) {
			printf("%d  ", head->value);
			head = head->pNext;
		}
	}
};

int main()
{
	Solution s;
	ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
	n1.pNext = &n2;
	n2.pNext = &n3;
	n3.pNext = &n4;
	n4.pNext = &n5;

	s.printList(s.reverseList(&n1));
	return 0;
}