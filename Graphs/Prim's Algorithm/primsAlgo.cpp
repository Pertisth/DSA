#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;


void primsAlgo(vector<pair<int, int>>list[], int v)
{
	vector<int>parent(v, -1);
	vector<int>key(v, INT_MAX);
	vector<bool>mst(v, false);
	parent[0] = -1;
	key[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>que;
	que.push({0, 0});

	for (int i = 0; i < v - 1; i++)
	{
		int min = que.top().first;
		int idx = que.top().second;
		que.pop();
		mst[idx] = true;
		for (auto x : list[idx])
		{
			int node = x.first;
			int weight = x.second;
			if (mst[node] == false && weight < key[node])
			{
				key[node] = weight;
				parent[node] = idx;
				que.push({key[node], node});
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
	primsAlgo(list, v);
	return 0;
}