#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;

void topo(vector<pair<int, int>>list[], vector<int>&dfs, int v, int node, stack<int>&st)
{
	dfs[node] = true;
	for (auto x : list[node])
	{
		if (dfs[x.first] == false)
		{
			topo(list, dfs, v, x.first, st);
		}

	}
	st.push(node);
}

int shortestPath(vector<pair<int, int>>list[], int v, int s, int d)
{
	// first find topological sort and store topo sort in stack
	stack<int>st;
	vector<int>dfs(v + 1, false);
	for (int i = 0; i < v; i++)
	{
		if (dfs[i] == false)
		{
			topo(list, dfs, v, i, st);
		}
	}

	// create dist array with infinity
	vector<int>dist(v + 1, INT_MAX);
	dist[s] = 0;
	while (!st.empty())
	{
		int node = st.top();
		st.pop();
		// if node was reached previously
		if (dist[node] != INT_MAX)
		{
			for (auto x : list[node])
			{
				if (dist[node] + x.second < dist[x.first])
				{
					dist[x.first] = dist[node] + x.second;
				}
			}
		}

	}
	//  print all the distance of various nodes from source;
	// for (int i = 0; i < v; i++)
	// {
	// 	if (dist[i] == INT_MAX)
	// 	{
	// 		cout << "INF " << " ";
	// 	}
	// 	else
	// 	{
	// 		cout << dist[i] << " ";
	// 	}
	// }
	return dist[d];
}


void addEdge(vector<pair<int, int>>list[], int e)
{
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		list[u].push_back({v, w});
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
	vector<pair<int, int>>list[v + 1];
	addEdge(list, e);
	int source, destination;
	cin >> source >> destination;
	cout << shortestPath(list, v, source, destination);

	return 0;
}