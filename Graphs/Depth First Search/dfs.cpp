#include<iostream>
#include<vector>
using namespace std;

void createAdjList(vector<int>adjList[], int m)
{
	// m is number of edges
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
}

void dfsRecursive(int node, vector<int>adjList[], vector<int>&vis, vector<int>&dfs)
{
	dfs.push_back(node);
	vis[node] = 1;
	for (auto x : adjList[node])
	{
		if (!vis[x])
		{
			dfsRecursive(x, adjList, vis, dfs);
		}

	}
}

vector<int> depthFirstSearch(vector<int>adjList[], int n)
{
	vector<int>vis(n + 1, 0);
	vector<int>dfs;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dfsRecursive(i, adjList, vis, dfs);
		}
	}
	return dfs;

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	vector<int>adjList[n + 1];
	createAdjList(adjList, m);

	vector<int>dfs = depthFirstSearch(adjList, n);
	for (int i = 0; i < dfs.size(); i++)
	{
		cout << dfs[i] << " ";
	}
	return 0;
}