#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int value;
	ListNode *Next;
	explicit ListNode(int x): value(x), Next(NULL) { }
};

void generate(ListNode* head, std::vector<int>& vec)
{
	if (head == NULL)
		return;
	vec.push_back(head->value);
	generate(head->Next, vec);
}

int main(int argc, char const *argv[])
{
	ListNode a(1), b(2), c(3);
	a.Next = &b;
	b.Next = &c;
	std::vector<int> vec;
	generate(&a, vec);
	for (int i = 0; i < vec.size(); ++i)
	{
		/* code */
		cout << vec[i] << endl;
	}
	return 0;
}