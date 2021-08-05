#include<iostream>
using namespace std;

class DisjointSet {
private:
	int parent[100000];
	int rank[100000];
public:
	void makeSet(int n)
	{
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
			rank[0];
		}
	}
	int findPar(int node)
	{
		if (node == parent[node])
		{
			return node;
		}
		return parent[node] = findPar(parent[node]);
	}

	void union(int u, int v)
	{
		u = findPar(u);
		v = findPar(v);
		if (rank[u] < rank[v])
		{
			parent[u] = v;
		}
		else if (rank[u] > rank[v])
		{
			parent[v] = u;
		}
		else
		{
			parent[v] = u;
			rank[u]++;
		}
	}
};

int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int u, v;
		cin >> u >> v;
		union(u, v);
	}

	return 0;
}