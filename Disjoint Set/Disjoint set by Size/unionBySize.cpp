#include<iostream>
using namespace std;


class DSU {

private:
	vector<int>parent;
	vector<int>size;
public:

	DSU(int n)
	{
		for (int i = 0; i < n; i++)
		{
			parent.push_back(i);
			size.push_back(1);
		}
	}

	int findPar(int node)
	{
		if (parent[node] == node)
		{
			return node;
		}
		parent[node] = findPar(parent[node]);
	}

	void unionBySize(int a, int b)
	{
		int parentA = findPar(a);
		int parentB = findPar(b);

		if (parentA == parentB)
		{
			return;
		}

		if (size[a] < size[b])
		{
			parent[a] = b;
			size[b] = size[b] + size[a];
		}
		else
		{
			parent[b] = a;
			size[a] = size[a] + size[b];
		}
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	return 0;
}