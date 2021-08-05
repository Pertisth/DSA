#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<int>list[], int v, int e)
{
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
	}

}

void topoSortDFS(vector<int>list[], vector<int>&vis, int node, stack<int>&st)
{
	vis[node] = 1;
	for (int x : list[node])
	{
		if (vis[x] == 0)
		{
			topoSortDFS(list, vis, x, st);
		}
	}
	st.push(node);
}

vector<int> topologicalSort(vector<int>list[], int v)
{
	vector<int>vis(v + 1, 0);
	stack<int>st;
	for (int i = 0; i < v; i++)
	{
		if (vis[i] == 0)
		{
			topoSortDFS(list, vis, i, st);
		}
	}
	vector<int>tSort;
	while (!st.empty())
	{
		int ele = st.top();
		st.pop();
		tSort.push_back(ele);
	}
	return tSort;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int v;
	cin >> v;
	int e;
	cin >> e;
	vector<int>adjList[v];
	addEdge(adjList, v, e);
	vector<int>ans = topologicalSort(adjList, v);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}