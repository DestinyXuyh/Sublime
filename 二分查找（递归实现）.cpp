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

bool binary_search(int sortArray[], int begin, int end, int target)
{
	if (begin > end)
	{
		/* code */
		return false;
	}
	int mid = (begin + end) / 2;
	if (target == sortArray[mid])
	{
		/* code */
		return true;
	}
	else if (target > sortArray[mid])
	{
		binary_search(sortArray, mid + 1, end, target);
	}
	else
	{
		binary_search(sortArray, begin, mid - 1, target);
	}

}

int main(int argc, char * argv[])
{
	int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//std::vector<int> vec = num;
	bool res = binary_search(num, 0, 9, 65);
	printf("%d\n", res);


	return 0;
}