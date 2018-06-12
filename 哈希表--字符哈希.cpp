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



int main()
{
	//字符的ASC2码的范围是0-127，故创建大小为128的int数组
	int char_map[128] = {0};
	string str = "abcdefgg";
	for (int i = 0; i < str.length(); ++i)
	{
		++char_map[str[i]];
	}
	for (int i = 0; i < 128; ++i)
	{
		if (char_map[i] > 0)
		{
			printf("[%c][%d]-----%d\n", i, i, char_map[i]);
		}
	}
	return 0;
}