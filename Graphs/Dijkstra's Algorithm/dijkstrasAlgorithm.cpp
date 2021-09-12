#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;



// pair<int,int> ===> first value = dist, second value = node
int dijkstraAlgorithm(vector<pair<int, int>>list[], int v, int s, int d)
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>que;
	vector<int>dist(v + 1, INT_MAX);
	dist[s] = 0;
	que.push({0, s});
	while (!que.empty())
	{
		pair<int, int> p = que.top();
		que.pop();

		// int prevDist = p.first;  //this line and next second line are same
		int prevNode = p.second;
		int prevDist = dist[prevNode];
		for (auto x : list[prevNode])
		{
			int currNode = x.first;
			int currDist = x.second;
			if (currDist + prevDist < dist[currNode])
			{
				dist[currNode] = currDist + prevDist;
				que.push({dist[currNode], currNode});
			}

		}
	}
	return dist[d];
}




void addEdge(vector<pair<int, int>>list[], int e)
{
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		list[u].push_back({v, w});
		list[v].push_back({u, w});
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
	vector<pair<int, int>>list[v + 1];
	addEdge(list, e);
	int source, destination;
	cin >> source >> destination;
	cout << dijkstraAlgorithm(list, v, source, destination);
	// for (int i = 1; i <= v; i++)
	// {
	// 	cout << i << "->";
	// 	for (auto x : list[i])
	// 	{
	// 		cout << x.first << " ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
}