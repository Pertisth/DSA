#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	int u;
	int v;
	int wt;
	Node(int x, int y, int w)
	{
		u = x;
		v = y;
		wt = w;
	}
};

void addEdge(vector<Node>&list, int e)
{
	for (int i = 0; i < e; i++)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		Node temp = Node(u, v, wt);
		list.push_back(temp);
	}
}

void bellmanFord(vector<Node>&list, int v, vector<int>&dist, int src)
{
	dist[src] = 0;
	for (int i = 1; i <= v - 1; i++)
	{
		for (auto x : list)
		{
			if (dist[x.u] + x.wt < dist[x.v])
			{
				dist[x.v] = dist[x.u] + x.wt;
			}
		}
	}

	bool flag = false;
	for (auto x : list)
	{
		if (dist[x.u] + x.wt < dist[x.v])
		{
			flag = true;
			cout << "Negative Loop exists" << endl;
			break;
		}
	}
	if (flag == false)
	{
		for (int i = 0; i < v; i++)
		{
			cout << dist[i] << " ";
		}
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
	vector<Node>list;
	addEdge(list, e);
	int maxVal = 1000000;
	vector<int>dist(v, maxVal);
	int src;
	cin >> src;
	bellmanFord(list, v, dist, src);

	return 0;
}