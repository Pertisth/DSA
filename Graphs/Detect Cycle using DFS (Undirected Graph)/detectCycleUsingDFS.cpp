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
		list[v].push_back(u);
	}
}
bool isCycle(vector<int>list[], vector<bool>&vis, int node, int parent)
{
	vis[node] = true;
	for (auto x : list[node])
	{
		if (vis[x] == false)
		{
			if (isCycle(list, vis, x, node))
			{
				return true;
			}
		}
		else if (x != parent)
		{
			return true;
		}
	}
	return false;
}

bool detectCycleDFS(vector<int>list[], int n, int m)
{
	vector<bool>vis(n + 1, false);
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == false)
		{
			if (isCycle(list, vis, i, -1))
			{
				return true;
			}
		}
	}
	return  false;
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
	addEdge(adjList, m);
	if (detectCycleDFS(adjList, n, m))
	{
		cout << "Cycle Detected " << endl;
	}
	else
	{
		cout << "No Cycle Detected " << endl;
	}

	return 0;

}