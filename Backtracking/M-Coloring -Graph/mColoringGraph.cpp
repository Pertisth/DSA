#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<int>list[], vector<int>&color, int node, int j)
{
	for (int x : list[node])
	{
		if (color[x] == j)
		{
			return false;
		}
	}
	return true;
}


bool coloring(vector<int>list[], int node, int v, int m, vector<int>&color)
{
	if (node == v + 1)
	{
		return true;
	}
	for (int i = 1; i <= m; i++)
	{
		if (isSafe(list, color, node, i))
		{
			color[node] = i;
			if (coloring(list, node + 1, v, m, color))
			{
				return true;
			}
			color[node] = -1;
		}
	}


	return false;
}





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
	int m;
	cin >> m ;

	vector<int>color(v + 1, -1);
	if (coloring(list, 1, v, m, color))
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	// print colors
	for (int i = 1; i <= v; i++)
	{
		cout << i << "-> " << color[i] << endl;
	}
	return 0;
}