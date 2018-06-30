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
	ListNode* detectCycle(ListNode* head)
	{
		ListNode* slow = head;	//慢指针
		ListNode* fast = head;	//快指针
		ListNode* meet = NULL;
		while (fast)
		{
			slow = slow->pNext;
			fast = fast->pNext;	//各走一步
			if (!fast)
			{
				return NULL;
			}
			fast = fast->pNext;
			if (slow == fast)
			{
				meet = fast;
				break;
			}
		}
		if (meet == NULL)
		{
			return NULL;
		}
		while (head && meet) {
			if(head == meet)
				return head;
			head=head->pNext;
			meet=meet->pNext;
		}
		return NULL;
	}
};

int main()
{
	Solution s;

	return 0;
}