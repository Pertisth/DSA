#include<iostream>
#include<vector>
using namespace std;

bool isPossible(int node, vector<int>list[], vector<int>&color, int col)
{
	for (int x : list[node])
	{
		if (color[x] == col)
		{
			return false;
		}
	}
	return true;
}

bool solve(int node, vector<int>list[], vector<int>&color, int m, int v)
{
	if (node == v)
	{
		return true;
	}
	for (int i = 1; i <= m; i++)
	{
		if (isPossible(node, list, color, i))
		{
			color[node] = i;
			if (solve(node + 1, list, color, m, v))
			{
				return true;
			}
			color[node] = 0;    /// bactracking
		}
	}
	return false;
}

bool graphColoring(vector<int>list[], vector<int>&color, int m, int v)
{

	if (solve(0, list, color, m, v))
	{
		return true;
	}
	return false;
}



void addEdge(vector<int>list[], int edges)
{
	for (int i = 0; i < edges; i++)
	{
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
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
	int m;
	cin >> m;
	vector<int>adjList[v];
	addEdge(adjList, e);
	vector<int>color(v, 0);
	if (graphColoring(adjList, color, m, v))
	{
		cout << "Success!!" << endl;;
		for (int i = 0; i < color.size(); i++)
		{
			cout << "Node " << i << " colored with  " << color[i] << endl;
		}
	}
	else
	{
		cout << "Not possible";
	}

	return 0;
}