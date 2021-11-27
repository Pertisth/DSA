#include<iostream>
using namespace std;

class DisjointSet {
private:
	int parent[100000];
	int rank[100000];
public:
	DisjointSet(int n)
	{
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
			rank[i] = 0;
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

	void unionR(int u, int v)
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

	int n;
	cin >> n;
	DisjointSet ds(n);
	int t;
	cin >> t;
	while (t--)
	{
		int u, v;
		cin >> u >> v;
		ds.unionR(u, v);
	}

	return 0;
}