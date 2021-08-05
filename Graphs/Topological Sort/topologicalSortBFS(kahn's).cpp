#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void addEdge(vector<int>adj[], int e)
{
	for (int i = 0; i < e; i++)
	{
		int  u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
}

// Kahn's Algo
void topologicalSortBFS(vector<int>adj[], int v)
{
	queue<int>que;
	vector<int>inDegree(v , 0);
	for (int i = 0; i < v; i++)
	{
		for (auto x : adj[i])
		{
			inDegree[x]++;
		}
	}
	for (int i = 0; i < inDegree.size(); i++)
	{
		if (inDegree[i] == 0)
		{
			que.push(i);
		}
	}
	vector<int>res;
	while (!que.empty())
	{
		int curr = que.front();
		res.push_back(curr);
		que.pop();
		for (auto x : adj[curr])
		{
			inDegree[x]--;
			if (inDegree[x] == 0)
			{
				que.push(x);
			}
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
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
	vector<int>adj[v];
	addEdge(adj, e);
	topologicalSortBFS(adj, v);

	return 0;
}