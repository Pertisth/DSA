#include<iostream>
#include<queue>
using namespace std;


void addEdge(vector<int>adjList[], int m)
{
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
}

///////////////////////////// BFS ///////////////////////////

bool checkBipartite(vector<int>list[], vector<int>&color, int node)
{
	queue<int>que;
	que.push(node);
	color[node] = 1;
	while (!que.empty())
	{
		int curr = que.front();
		que.pop();
		for (auto x : list[curr])
		{
			if (color[x] == -1)
			{
				que.push(x);
				color[x] = 1 - color[curr];
			}
			else if (color[x] == color[curr])
			{
				return false;
			}
		}
	}
	return true;
}

bool bipartiteBFS(vector<int>list[], int n)
{
	vector<int>color(n + 1, -1);
	for (int i = 1; i <= n; i++)
	{
		if (color[i] == -1)
		{
			if (!checkBipartite(list, color, i))
			{
				return false;
			}
		}
	}
	return true;
}

///////////// BFS /////////////////////


//////////// DFS /////////////////////

bool DFSBipartite(vector<int>list[], vector<int>&color, int node)
{
	if (color[node] == -1)
	{
		color[node] = 1;
	}

	for (int x : list[node])
	{
		if (color[x] == -1)
		{
			color[x] = 1 - color[node];
			if (!DFSBipartite(list, color, x))
			{
				return false;
			}

		}
		else if (color[x] == color[node])
		{
			return false;
		}
	}
	return true;
}

bool bipartiteDFS(vector<int>list[], int n)
{
	vector<int>color(n + 1, -1);
	for (int i = 1; i <= n; i++)
	{
		if (color[i] == -1)
		{
			if (!DFSBipartite(list, color, i))
			{
				return false;
			}
		}
	}
	return true;
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
	if (bipartiteDFS(adjList, v))
	{
		cout << "All nodes are coloured ";
	}
	else
	{
		cout << "Coloring not possible";
	}
	return 0;
}