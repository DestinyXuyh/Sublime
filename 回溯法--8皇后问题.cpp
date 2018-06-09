#include <iostream>
#include <vector>
#include <string>
using namespace std;

//更新棋盘
static const int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
static const int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
void put_down_the_queen(int x, int y, vector<vector<int> > &mark)
{
	mark[x][y] = 1;
	for (int i = 1; i < mark.size(); ++i)
	{
		for (int j = 0; j < 8; j++)
		{
			int new_x = x + i * dx[j];
			int new_y = y + i * dy[j];
			if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size())
				mark[new_x][new_y] = 1;
		}
	}
}

void printMark(vector<vector<int> >& mark)
{
	for (int i = 0; i < mark.size(); ++i)
	{
		for (int j = 0; j < mark[i].size(); ++j)
		{
			printf("%d ", mark[i][j]);
		}
		printf("\n");
	}
}

void printLocation(vector<string>& location)
{
	for (int i = 0; i < location.size(); ++i)
	{
		for (int j = 0; j < location[i].length(); ++j)
		{
			printf("%c ", location[i][j]);
		}
		printf("\n");
	}
}

void generate(int k, int n,	//k代表正在放第k行皇后
              vector<string>& location,	//某次结果存储在location中
              vector<vector<string> >& result, //最终结果
              vector<vector<int> >& mark	//表示标记棋盘的数组
             )
{
	if (k == n)
	{
		result.push_back(location);
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		//第0列到第n-1列循环放置皇后
		if (mark[k][i] == 0)
		{
			/* 该位置可以放置皇后 */
			vector<vector<int> > tmp = mark;
			location[k][i] = 'Q';
			put_down_the_queen(k, i, mark);
			generate(k + 1, n, location, result, mark);
			mark = tmp;
			location[k][i] = '.';
		}
	}
}

int main(int argc, char const *argv[])
{
	int n = 5;
	//初始化mark
	vector<vector<int> > mark;
	for (int i = 0; i < n; ++i)
	{
		mark.push_back(vector<int>());
		for (int j = 0; j < n; ++j)
		{
			mark[i].push_back(0);
		}
	}
	//初始化location
	vector<string> location;
	for (int i = 0; i < n; ++i)
	{
		location.push_back(string());
		for (int j = 0; j < n; ++j)
		{
			location[i] += '.';
		}
	}
	vector<vector<string> > result;
	generate(0, n, location, result, mark);
	//printMark(mark);
	//printLocation(location);
	for (int i = 0; i < result.size(); ++i)
	{
		printLocation(result[i]);
		printf("\n");
	}
	return 0;
}