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

typedef struct tagStudentInfo
{
	int nID;
	string strName;
	bool operator < (tagStudentInfo const& _A) const
	{
		if (nID < _A.nID)
			return true;
		if (nID == _A.nID)
			return strName.compare(_A.strName) < 0;
		return false;
	}
} StudentInfo, *PStudentInfo; //PStudentInfo 表示指针类型

int main()
{
	int nSize;
	map<StudentInfo, int> mapStudent;
	map<StudentInfo, int>:: iterator iter;
	StudentInfo s;
	s.nID = 1;
	s.strName = "cindy";
	mapStudent.insert(pair<StudentInfo, int>(s, 90));
	s.nID = 2;
	s.strName = "tom";
	mapStudent.insert(make_pair(s, 80));
	for (iter = mapStudent.begin(); iter != mapStudent.end(); ++iter)
	{
		cout << iter->first.nID << ' ' << iter->first.strName << ' ' << iter->second << std::endl;;
	}
	return 0;
}