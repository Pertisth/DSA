#include<iostream>
#include<vector>
#include<utility>
using namespace std;


void primsAlgo(vector<pair<int, int>>list[], int v, int e)
{
	vector<int>parent(v, -1);
	vector<int>key(v, INT_MAX);
	vector<bool>mst(v, false);
	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < v - 1; count++)
	{
		int min = INT_MAX;
		int idx;
		for (int i = 0; i < v; i++)
		{
			if (mst[i] == false && key[i] < min)
			{
				min = key[i];
				idx = i;
			}
		}

		mst[idx] = true;

		for (auto x : list[idx])
		{
			int node = x.first;
			int weight = x.second;
			if (mst[node] == false && weight < key[node])
			{
				key[node] = weight;
				parent[node] = idx;
			}
		}
	}

	for (int i = 0; i < v; i++)
	{
		cout << parent[i] << " ";
	}

}

void addEdge(vector<pair<int, int>>list[], int e)
{
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		list[u].push_back({v, w});
		list[v].push_back({u, w});
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
	primsAlgo(list, v, e);
	return 0;
}