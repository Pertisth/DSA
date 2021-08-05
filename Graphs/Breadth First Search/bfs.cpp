#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void adjList(vector<int>list[], int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
}


vector<int> bfs(vector<int>list[], int n)
{
	vector<int>res;
	vector<bool>vis(n + 1, false);
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			queue<int>que;
			que.push(i);
			vis[i] = true;
			while (!que.empty())
			{
				int node = que.front();
				que.pop();
				res.push_back(node);
				for (auto x : list[node])
				{
					if (!vis[x])
					{
						que.push(x);
						vis[x] = true;
					}
				}
			}
		}

	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector<int>list[n + 1];
	adjList(list, n, m);
	vector<int>res = bfs(list, n);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;

}