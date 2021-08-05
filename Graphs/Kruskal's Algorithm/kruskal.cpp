#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

class Node {
public:
	int u, v, wt;
	Node(int x, int y, int z)
	{
		u = x;
		v = y;
		wt = z;
	}
};


bool myComp(Node a, Node b)
{
	return a.wt < b.wt;
}

void addEdge(vector<Node>&edges, int m)
{
	for (int i = 0; i < m; i++)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		Node newNode = Node(u, v, wt);
		edges.push_back(newNode);
	}
}

int findPar(int x, vector<int>&parent)
{
	if (parent[x] == x)
	{
		return x;
	}
	return parent[x] = findPar(parent[x] , parent);
}

void unionn(int u, int v, vector<int>&parent, vector<int>&rank)
{
	u = findPar(u, parent);
	v = findPar(v, parent);
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
		parent[u] = v;
		rank[v]++;
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
	vector<Node>edges;
	addEdge(edges, e);
	sort(edges.begin(), edges.end(), myComp);
	vector<pair<int, int>>mst;
	vector<int>parent(v, 0);
	vector<int>rank(v, 0);
	for (int i = 0; i < v; i++)
	{
		parent[i] = i;
	}

	int cost = 0;
	for (auto x : edges)
	{
		int upar = findPar(x.u, parent);
		int vpar = findPar(x.v, parent);
		if (upar != vpar)
		{
			cost = cost + x.wt;
			mst.push_back({x.u, x.v});
			unionn(x.u, x.v, parent, rank);
		}
	}

	cout << "Cost : " << cost << endl;
	for (auto x : mst)
	{
		cout << x.first << " " << x.second << endl;
	}

	return 0;
}

