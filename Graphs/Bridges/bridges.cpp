#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int>list[], int e)
{
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
}


void dfs(vector<int>list[], int node, int parent, vector<int>&tin, vector<int>&low, vector<bool>&vis, int &timer)
{
	vis[node] = true;
	tin[node] = timer;
	low[node] = timer;
	timer++;
	for (auto x : list[node])
	{
		if (x == parent) // previously visited
		{
			continue;
		}

		if (vis[x] == false)
		{
			dfs(list, x, node, tin, low, vis, timer);
			low[node] = min(low[node], low[x]);
			if (low[x] > tin[node])
			{
				cout << node << " " << x << endl;
			}
		}
		else
		{
			low[node] = min(low[node], tin[x]);
		}
	}
}


void findBridges(vector<int>list[], int v)
{
	vector<int>tin(v + 1, -1);
	vector<int>low(v + 1, -1);
	vector<bool>vis(v + 1, false);
	int timer = 0;
	for (int i = 1; i <= v; i++)
	{
		if (vis[i] == false)
		{
			dfs(list, i, -1, tin, low, vis, timer);
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int v, e;
	cin >> v >> e;
	vector<int>list[v + 1];
	addEdge(list, e);

	findBridges(list, v);
	return 0;
}