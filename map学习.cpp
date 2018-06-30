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

//比较函数
bool fncomp(char lhs, char rhs)
{
	return lhs < rhs;
}

//
struct classcomp
{
	//重载()运算符
	bool operator()(const char& lhs, const char& rhs)
	{
		return lhs < rhs;
	}
};


int main()
{
	//map的多种构造函数
	//1.直接定义
	map<char, int> mymap;
	mymap['a'] = 1;
	mymap['b'] = 2;
	mymap['c'] = 3;

	//复制
	map<char, int> second = mymap;
	map<char, int> second2(mymap);

	//3.通过迭代器
	map<char, int> third(mymap.begin(), mymap.end());

	//4.重新定义 Compare 对象，该对象内部对运算符 () 进行重载
	map<char, int, classcomp> fourth;

	//5.通过函数指针
	bool (*fn_pt)(char, char) = fncomp;
	map<char, int, bool(*)(char, char)> fifth(fn_pt);




	//map遍历输出
	map<char, int>::iterator iter = second2.begin();
	for (; iter != second2.end(); ++iter)
	{
		printf("%c---%d\n", iter->first, iter->second);
	}
	printf("=================\n");
	second2.clear();
	second2['a'] = 6;
	second2['b'] = 10023;
	while (!second2.empty()) {
		printf("%c------>%d\n", second2.begin()->first, second2.begin()->second);
		second2.erase(second2.begin());
	}
	printf("====================\n");
	second2.insert(pair<char, int>('c', 100));
	second2.insert(pair<char, int>('d', 200));
	second2.insert(make_pair('a', 300));
	printf("c------>%d\n", second2.find('c')->second);
	printf("d------>%d\n", second2.find('d')->second);
	printf("====================\n");

	map<char, int>::iterator ite = second2.begin();
	for (; ite != second2.end(); ++ite)
	{
		printf("%c---%d\n", ite->first, ite->second);
	}

	char highest = second2.rbegin()->first;
	printf("%c\n", highest);
	return 0;
}