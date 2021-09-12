#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<int>list[], int e)
{
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
	}
}

void dfs(vector<int>list[], int node, vector<bool>&vis)
{
	vis[node] = true;
	cout << node << " ";
	for (int x : list[node])
	{
		if (vis[x] == false )
		{
			dfs(list, x, vis);
		}
	}
}

void topo(vector<int>list[], stack<int>&st, vector<bool>&vis, int node)
{
	vis[node] = true;
	for (int x : list[node])
	{
		if (vis[x] == false)
		{
			topo(list, st, vis, x);
		}
	}
	st.push(node);
}

void kosaRajusAlgo(vector<int>list[], int v)
{
	// step 1 : Find toposort
	stack<int>st;
	vector<bool>vis(v + 1, false);
	for (int i = 1; i <= v; i++)
	{
		if (vis[i] == false)
		{
			topo(list, st, vis, i);
		}
	}

	// step 2 : transpose edges
	vector<int>transpose[v + 1];
	for (int i = 1; i <= v; i++)
	{
		vis[i] = false;
		for (int x : list[i])
		{
			transpose[x].push_back(i);
		}
	}

	// step 3 : print vertices according to the time visited earlier
	int count = 0;
	while (!st.empty())
	{
		int node = st.top();
		st.pop();
		if (vis[node] == false)
		{
			dfs(transpose, node, vis);
			count++;
			cout << endl;
		}

	}
	cout << "Count : " << count << endl;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, e;
	cin >> n >> e;
	vector<int>list[n + 1];
	addEdge(list, e);
	kosaRajusAlgo(list, n);
	return 0;
}