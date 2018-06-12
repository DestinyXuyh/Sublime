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
	bool wordPattern(string str, string pattern)
	{
		std::map<string, char> word_map;	//单词到pattern字符的映射
		int used[128] = {0};

		//按空格分割单词
		std::vector<string> vec_str;
		string tmp;
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == ' ')
			{
				vec_str.push_back(tmp);
				tmp = "";
			}
			else
			{
				tmp += str[i];
			}
		}
		vec_str.push_back(tmp);

		if (vec_str.size() != pattern.length())
			return false;

		for (int i = 0; i < vec_str.size(); ++i)
		{
			if (word_map.find(vec_str[i]) == word_map.end())
			{
				/* 没有出现过 */
				if (used[pattern[i]])
					return false;
				else
				{
					word_map.insert(make_pair(vec_str[i], pattern[i]));
					used[pattern[i]] = 1;
				}

			}
			else
			{
				//出现过
				if (word_map[vec_str[i]] != pattern[i])
					return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;

	string str = "dog cat cat dog";
	string pattern = "abba";
	//printf("%d\n", s.wordPattern(str, pattern));
	bool res = s.wordPattern(str, pattern);
	cout << res << endl;
	return 0;
}