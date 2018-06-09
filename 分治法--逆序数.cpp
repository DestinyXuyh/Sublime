#include <iostream>
#include <vector>
using namespace std;

void merge(vector<pair<int, int> >& vec1,
           vector<pair<int, int> >& vec2,
           vector<pair<int, int> >& vec,
           vector<int>& count)
{
	int i = 0;
	int j = 0;
	while (i < vec1.size() && j < vec2.size())
	{
		if (vec1[i].first <= vec2[j].first)
		{
			count[vec1[i].second] += j;
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
		count[vec1[i].second] += j;
		vec.push_back(vec1[i]);
		++i;
	}
	while (j < vec2.size())
	{
		vec.push_back(vec2[j]);
		++j;
	}
}

void merge_sort(vector<pair<int, int> >& vec, vector<int>& count)
{
	if (vec.size() == 1)
		return;
	int mid = vec.size() / 2;
	vector<pair<int, int> > vec1;
	vector<pair<int, int> > vec2;
	for (int i = 0; i < mid; ++i)
	{
		vec1.push_back(vec[i]);
	}
	for (int i = mid; i < vec.size(); ++i)
	{
		vec2.push_back(vec[i]);
	}
	merge_sort(vec1, count);
	merge_sort(vec2, count);
	vec.clear();
	merge(vec1, vec2, vec, count);
}

vector<int> countSmaller(vector<int>& nums)
{
	vector<pair<int, int> > vec;
	vector<int> count;
	//初始化vec
	for (int i = 0; i < nums.size(); ++i)
	{
		vec.push_back(make_pair(nums[i], i));
		count.push_back(0);
	}
	merge_sort(vec, count);
	return count;
}

int main(int argc, char const *argv[])
{
	vector<int> nums;
	vector<int> count;

	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(9);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(-2);
	nums.push_back(1);

	count = countSmaller(nums);
	for (int i = 0; i < count.size(); ++i)
	{
		printf("%d ", count[i]);
	}
	return 0;
}