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

//图的邻接表数据结构
struct GraphNode
{
	int lable;
	std::vector<GraphNode* > neighbors;
	GraphNode(int a): lable(a) {}
};

void dfs_graph(GraphNode* node, int visit[])
{
	visit[node->lable] = 1;
	printf("%d ", node->lable);
	for (int i = 0; i < node->neighbors.size(); ++i)
	{
		/* code */
		if (visit[node->neighbors[i]->lable] == 0)
		{
			/* code */
			dfs_graph(node->neighbors[i], visit);
		}
	}
}

int main(int argc, char * argv[])
{
	const int MAX_N = 5;  //图的节点数
	GraphNode* graph[MAX_N];
	for (int i = 0; i < MAX_N; ++i)
	{
		/* code */
		graph[i] = new GraphNode(i);
	}
	graph[0]->neighbors.push_back(graph[4]);
	graph[0]->neighbors.push_back(graph[2]);
	graph[1]->neighbors.push_back(graph[0]);
	graph[1]->neighbors.push_back(graph[2]);
	graph[2]->neighbors.push_back(graph[3]);
	graph[3]->neighbors.push_back(graph[4]);
	graph[4]->neighbors.push_back(graph[3]);

	int visit[MAX_N] = {0};
	for (int i = 0; i < MAX_N; ++i)
	{
		/* code */
		if (visit[i] == 0)
		{
			/* code */
			printf("from lable(%d) : ", graph[i]->lable);
			dfs_graph(graph[i], visit);
			printf("\n");
		}
	}

	for (int i = 0; i < MAX_N; ++i)
	{
		/* code */
		delete graph[i];
	}

	return 0;
}