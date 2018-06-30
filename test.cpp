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


void fun(int (&a)[3])
{
	cout << sizeof(a) << endl;;
}
int main()
{
	/*int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int len = sizeof(a) / sizeof(int);
	sort(a, a + len, less<int>());
	for (int i = 0; i < len; ++i)
	{
		printf("%d\n", a[i]);
	}*/

	/*int a[3] = {0};
	cout << sizeof(a) << endl;

	fun(a);

	int *p = &a[0];
	cout << sizeof(p) << std::endl;*/

	//数组名的使用
	/*int a[] = {1, 2, 3, 4, 5};
	cout<<&a<<endl;
	cout<<&a+1<<endl;
	cout<<*(&a)<<endl;
	cout<<*(&a+1)<<endl;
	cout<<*(*(&a+1)-1)<<endl;
	cout<<*a<<endl;
	cout<<a<<endl;*/

	//new的使用
	/*int *p=new int[5];
	for (int i = 0; i < 5; ++i)
	{
		p[i] = i+3;
		printf("%d\n", p[i]);
	}
	cout<<*(p+1)<<endl;
	delete[]p;*/

	//指针、数组、c语言
	char ch[]="abc\0def", *p=ch;
	cout<<*(p+4)<<std::endl;
	cout<<p<<std::endl;
	std::cout<< p+3 <<std::endl;
	std::cout<< p+4 <<std::endl;

	printf("%s\n", ch);
	printf("%c\n", ch+1);
	cout<<'a'+2<<endl;
	return 0;

}