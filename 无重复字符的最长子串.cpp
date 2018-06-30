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
	int lengthOfLongestSubstring(string s)
	{
		int begin = 0;
		int result = 0;
		string word;
		int char_map[128] = {0};
		for (int i = 0; i < s.length(); ++i)
		{
			char_map[s[i]] += 1;
			if (char_map[s[i]] == 1)
			{
				word = s.substr(begin, i - begin + 1);
				if (word.size() > result)
				{
					result = word.size();
				}
			}
			else
			{
				while (char_map[s[i]] != 1)
				{
					char_map[s[begin++]]--;
				}
				word = s.substr(begin, i - begin + 1);
				if (word.size() > result)
				{
					result = word.size();
				}
			}

		}
		return result;
	}
};

int main()
{
	Solution s;
	string str = "abcbacdbcf";
	int res = s.lengthOfLongestSubstring(str);
	printf("%d\n", res);
	return 0;
}