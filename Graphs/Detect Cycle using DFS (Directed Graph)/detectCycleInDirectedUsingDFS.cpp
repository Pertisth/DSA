#include<iostream>
#include<vector>
using namespace std;


void addEdge(vector<int>list[], int m)
{
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
	}
}

bool detectLoopUtil(vector<int>list[], vector<bool>&vis, vector<bool>&dfsvis, int node)
{
	vis[node] = true;
	dfsvis[node] = true;
	for (int x : list[node])
	{
		if (vis[x] == true && dfsvis[x] == true)
		{
			return true;
		}
		else if (vis[x] == false)
		{
			if (detectLoopUtil(list, vis, dfsvis, x))
			{
				return true;
			}

		}
	}
	dfsvis[node] = false;         // backtracking
	return false;
}

bool detectLoop(vector<int>list[], int n)
{
	vector<bool>vis(n + 1, false);
	vector<bool>dfsvis(n + 1, false);
	for (int i = 0; i <= n; i++)
	{
		if (vis[i] == false)
		{
			if (detectLoopUtil(list, vis, dfsvis, i))
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
	int v, e;
	cin >> v >> e;
	vector<int>adjList[v + 1];
	addEdge(adjList, e);
	if (detectLoop(adjList, v))
	{
		cout << "Loop Found";
	}
	else
	{
		cout << "No Loop";
	}
	return 0;
}