#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int>adjList[], int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

}

bool cycleDetect(vector<int>adjlist[], vector<bool>&vis, int node)
{
	queue<pair<int, int>>que;
	vis[node] = true;
	que.push({node, -1});
	while (!que.empty())
	{
		int node = que.front().first;
		int par = que.front().second;
		que.pop();
		for (auto x : adjlist[node])
		{
			if (!vis[x])
			{
				vis[x] = true;
				que.push({x, node});
			}
			else if (par != x)
			{
				return true;
			}
		}
	}
	return false;
}

bool detectLoop(vector<int>adjlist[], int n)
{
	vector<bool>vis(n + 1, false);
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			if (cycleDetect(adjlist, vis, i))
			{
				return true;
			}
		}
	}
	return false;
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
	addEdge(adjList, n, m);
	cout << detectLoop(adjList, n);
	return 0;
}