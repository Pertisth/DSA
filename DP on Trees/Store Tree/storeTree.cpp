#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int>list[], int parent)
{
	cout << node << " ";
	for (int it : list[node])
	{
		if (it != parent)
		{
			dfs(it, list, node);
		}
	}
}

int subTreeCount[100005];
void countSubTree(int node, vector<int>list[], int parent)
{
	subTreeCount[node] = 1;
	for (int i : list[node])
	{
		if (i != parent)
		{
			countSubTree(i, list, node);
			subTreeCount[node] = subTreeCount[node] + subTreeCount[i];
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int edges;
	cin >> edges;
	vector<int>adjList[n + 1];
	while (edges--)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	// dfs(1, adjList, -1);
	countSubTree(1, adjList, -1);
	cout << subTreeCount[1];
	return 0;
}