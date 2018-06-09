#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

void merge(std::vector<int>& vec1, vector<int>& vec2, vector<int>& vec)
{
	int i = 0;
	int j = 0;
	while (i < vec1.size() && j < vec2.size())
	{
		if (vec1[i] <= vec2[j])
		{
			vec.push_back(vec1[i]);
			++i;
		}
		else
		{
			vec.push_back(vec2[j]);
			++j;
		}
	}
	while (i < vec1.size())
	{
		vec.push_back(vec1[i]);
		++i;
	}
	while (j < vec2.size())
	{
		vec.push_back(vec2[j]);
		++j;
	}
}

void merge_sort(vector<int>& vec)
{
	if (vec.size() == 1)
		return;
	int mid = vec.size() / 2;
	vector<int> vec1;
	vector<int> vec2;
	for (int i = 0; i < mid; ++i)
	{
		vec1.push_back(vec[i]);
	}
	for (int i = mid; i < vec.size(); ++i)
	{
		vec2.push_back(vec[i]);
	}
	merge_sort(vec1);
	merge_sort(vec2);
	vec.clear();
	merge(vec1, vec2, vec);
}

int main(int argc, char const *argv[])
{

	return 0;
}