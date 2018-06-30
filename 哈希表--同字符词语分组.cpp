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
	vector<vector<string> > groupAnagrams(vector<string>& strs)
	{
		//建立哈希表
		std::map<string, vector<string> > anagram;
		vector<vector<string> > result;
		for (int i = 0; i < strs.size(); ++i)
		{
			//对str[i]进行排序
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			if (anagram.find(tmp) == anagram.end())
			{
				//map里没找到tmp的关键字，就加入
				anagram.insert(make_pair(tmp, vector<string>()));
				anagram[tmp].push_back(strs[i]);
			}
			else
			{
				anagram[tmp].push_back(strs[i]);
			}
		}

		//用迭代器遍历map
		std::map<string, vector<string> >::iterator iter = anagram.begin();
		for (; iter != anagram.end(); ++iter)
		{
			result.push_back(vector<string>());
			for (int i = 0; i < iter->second.size(); ++i)
			{
				result.back().push_back(iter->second[i]);
			}
		}

		return result;
	}
};

bool cmp(const char& a, const char& b)
{
	return a < b;
}

int main()
{
	Solution s;
	vector<vector<string> > result;
	//字符串数组
	string str[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> strs;
	for (int i = 0; i < 6; ++i)
	{
		strs.push_back(str[i]);
	}
	result = s.groupAnagrams(strs);
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			printf("[%s]", result[i][j].c_str());
		}
		printf("\n");
	}
	return 0;
}