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

void dfs(vector<int>list[], vector<int>&disc, vector<int>&low, vector<bool>&vis, int node, int parent, vector<int>&articulationList, int timer)
{
	vis[node] = true;
	disc[node] = timer;
	low[node] = timer;
	timer++;
	int child = 0;
	for (int x : list[node])
	{
		if (x == parent)
		{
			continue;
		}
		if (vis[x] == false)
		{
			dfs(list, disc, low, vis, x, node, articulationList, timer);
			low[node] = min(low[node], low[x]);
			child++;
			if (low[x] >= disc[node] && parent != -1)
			{
				articulationList[node] = 1;
			}
		}
		else
		{
			low[node] = min(low[node], disc[x]);
		}

	}
	if (parent == -1 && child > 1)
	{
		articulationList[node] = 1;
	}
}

void articulationPoint(vector<int>list[], int v)
{
	vector<int>disc(v, -1);
	vector<int>low(v, -1);
	vector<bool>vis(v, false);
	vector<int>articulationList(v, -1);
	int timer = 0;
	for (int i = 0; i < v; i++)
	{
		if (vis[i] == false)
		{
			dfs(list, disc, low, vis, i, -1, articulationList, timer);
		}
	}
	for (int i = 0; i < v; i++)
	{
		if (articulationList[i] == 1)
		{
			cout << i << " ";
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
	articulationPoint(list, v);
	return 0;
}