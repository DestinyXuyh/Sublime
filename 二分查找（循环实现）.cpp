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

bool binary_search(std::vector<int> array, int target)
{
	int size = array.size();
	if (size == 0)
		return false;
	int begin = 0;
	int end = size - 1;
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		if (target == array[mid])
		{
			return true;
		}
		else if (target < array[mid])
		{
			end = mid - 1;
		}
		else if (target > array[mid])
		{
			begin = mid + 1;
		}
	}
	return false;
}

int main(int argc, char * argv[])
{
	int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
	{
		vec.push_back(num[i]);
	}
	bool res = binary_search(vec, 4);
	printf("%d\n", res);

	return 0;
}