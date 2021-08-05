#include<iostream>
#include<queue>
#include<vector>
using namespace std;


void addEdge(int v, int e, vector<int>list[])
{
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
}


int shortestPath(vector<int>list[], int v, int e, int s, int d)
{
	queue<int>que;
	vector<int>dist(v + 1, INT_MAX);
	que.push(s);
	dist[s] = 0;
	while (!que.empty())
	{
		int node = que.front();
		que.pop();
		int d = dist[node];
		for (auto x : list[node])
		{
			if (d + 1 < dist[x])
			{
				dist[x] = d + 1;
				que.push(x);
			}
		}
	}
	// for (int i = 0; i < v + 1; i++)
	// {
	// 	cout << dist[i] << " ";
	// }

	// cout << endl;
	return dist[d];
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int v;
	int e;
	cin >> v >> e;
	vector<int>adjList[v + 1];
	addEdge(v, e, adjList);
	int source, destination;
	cin >> source >> destination;
	cout << shortestPath(adjList, v, e, source, destination);
	return 0;
}