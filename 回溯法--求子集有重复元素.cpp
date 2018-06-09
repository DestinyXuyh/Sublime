#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	std::vector<std::vector<int> > subsetsWithDup(std::vector<int>& nums)
	{
		std::vector<std::vector<int> > result;
		std::vector<int> item;
		std::set<std::vector<int> > res_set;
		//先排序
		sort(nums.begin(), nums.end());
		result.push_back(item);
		generate(0, nums, result, item, res_set);

		return result;
	}
private:
	void generate(int i, std::vector<int>& nums, std::vector<std::vector<int> >& result, vector<int>& item, set<vector<int> >& res_set)
	{
		if (i >= nums.size())
			return;
		item.push_back(nums[i]);
		if (res_set.find(item) == res_set.end())
		{
			/* 没有找到item */
			result.push_back(item);
			res_set.insert(item);
		}
		generate(i + 1, nums, result, item, res_set);
		item.pop_back();
		generate(i + 1, nums, result, item, res_set);
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	vector<vector<int> > result;
	Solution s;
	result = s.subsetsWithDup(nums);
	for (int i = 0; i < result.size(); ++i)
	{
		/* code */
		if (result[i].size() == 0)
		{
			printf("[]");
		}
		for (int j = 0; j < result[i].size(); ++j)
		{
			printf("[%d]", result[i][j]);
		}
		cout << endl;
	}
	return 0;
}