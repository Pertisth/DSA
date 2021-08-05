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
	for (int i = 0; i < v; i++)
	{
		cout << i << " -> ";
		for (int x : list[i])
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}