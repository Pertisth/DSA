#include<iostream>
#include<vector>
using namespace std;


void addEdge(vector<long long>list[], int n)
{
	for (int i = 2; i <= n; i++)
	{
		int ele;
		cin >> ele;
		list[i].push_back(ele);
		list[ele].push_back(i);
	}
}

long long parent[2 * (int)1e5][30];
void dfs(vector<long long>list[], int node, int par = -1)
{
	parent[node][0] = par;

	for (int i = 1; i <= 29; i++)
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

long long kthParent(long long k, long long node)
{
	long long count = 0;
	while (k)
	{
		if (k & 1)
		{
			node = parent[node][count];
		}
		count++;
		k = k >> 1;
	}
	return node;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long n, q;
	cin >> n >> q;
	vector<long long>list[n + 1];
	addEdge(list, n);
	dfs(list, 1);
	while (q--)
	{
		long long node, k;
		cin >> node >> k;
		long long res = kthParent(k, node);
		if (res == 0)
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << res << endl;
		}
	}
	return 0;
}