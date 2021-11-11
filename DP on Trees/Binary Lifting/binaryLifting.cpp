#include<iostream>
#include<vector>
using namespace std;

void addEgdes(vector<int>list[], int n)
{
	for (int i = 1; i < 10; i++)
	{
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
}

int parent[100005][17];
void dfs(vector<int>list[], int node, int par = 0)
{
	parent[node][0] = par;
	for (int i = 1; i <= 16; i++)
	{
		parent[node][i] = parent[parent[node][i - 1]][i - 1];
	}
	for (int x : list[node])
	{
		if (x != par)
		{
			dfs(list, x, node);
		}
	}
}

int kthParent(int node, int k)
{
	int count = 0;
	while (k)
	{
		//kth set bit
		if (k & 1 == 1)
		{
			node = parent[node][count];
		}
		k = k >> 1;
		count++;
	}
	return node;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int>list[n + 1];
	addEgdes(list, n);
	dfs(list, 1);
	cout << kthParent(6, 1);
	return 0;

}