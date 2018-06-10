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

int main(int argc, char * argv[])
{
	
	const int MAX_N = 5;
	int Graph[MAX_N][MAX_N] = {0};
	Graph[0][2] = 1;
	Graph[0][4] = 1;
	Graph[1][0] = 1;
	Graph[1][2] = 1;
	Graph[2][3] = 1;
	Graph[3][4] = 1;
	Graph[4][3] = 1;

	printf("Graph:\n");
	for (int i = 0; i < MAX_N; ++i)
	{
		for (int j = 0; j < MAX_N; ++j)
		{
			printf("%d ", Graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}