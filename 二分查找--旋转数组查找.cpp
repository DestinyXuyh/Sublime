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
using namespace std;

class Solution
{
public:
	int search(std::vector<int>& nums, int target)
	{
		int begin = 0;
		int end   = nums.size() - 1;
		while (begin <= end) {
			/* 循环 */
			int mid = (begin + end) / 2;
			if (target == nums[mid])
			{
				return mid;
			}
			else if (target > nums[mid])
			{
				if (nums[begin] < nums[mid])
				{
					/* 递增数组在前面，旋转数组在后面，target在后面 */
					begin = mid + 1;
				}
				else if (nums[begin] > nums[mid])
				{
					/* 递增数组在后面，旋转数组在前面，target在两侧都有可能 */
					if (target < nums[begin])
					{
						begin = mid + 1;
					}
					else
						end = mid - 1;
				}
				else if (nums[begin] == nums[mid])
					begin = mid + 1;
			}
			else if (target < nums[mid])
			{
				if (nums[begin] < nums[mid])
				{
					/* code */
					if (target >= nums[begin])
						end = mid - 1;
					else
						begin = mid + 1;
				}
				else if (nums[begin] > nums[mid])
				{
					end = mid - 1;
				}
				else if (nums[begin] == nums[mid])
				{
					begin = mid + 1;
				}
			}
		}
		return -1;
	}
};

int main()
{
	Solution s;
	
	int numbers[] = {5, 6, 7, 8, 9, 0, 1, 2, 3, 4};
	int size = sizeof(numbers) / sizeof(int);
	std::vector<int> nums;
	//printf("%d\n", size);
	for (int i = 0; i < size; ++i)
	{
		/* code */
		nums.push_back(numbers[i]);
	}

	int test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> res;
	for (int i = 0; i < 10; ++i)
	{
		/* code */
		int tmp = s.search(nums, test[i]);
		res.push_back(tmp);
	}
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}