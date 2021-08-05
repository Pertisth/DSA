#include<iostream>
#include<vector>
#include<array>
using namespace std;


vector<vector<int>> createGraphAdjacencyMatrix(int n, int m)
{
	vector<vector<int>>adjMatrix(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adjMatrix[u][v] = 1;
		adjMatrix[v][u] = 1;    // incase of directed graph omit this line
	}
	return adjMatrix;
}

void createGraphAdjList(vector<int>adjList[], int n, int m)
{
	//vector<int>adjList[n + 1];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u); // incase of directed graph omit this line
	}

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	//vector<vector<int>>adjMatrix = createGraphAdjacencyMatrix(n, m);
	// for (int i = 0; i < n + 1; i++)
	// {
	// 	for (int j = 0; j < n + 1; j++)
	// 	{
	// 		cout << adjList[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }



	vector<int>adjList[n + 1];
	createGraphAdjList(adjList, n, m);
	for (int i = 1; i < n + 1; i++)
	{
		cout << i << " --> ";
		for (int j = 0; j < adjList[i].size(); j++)
		{
			cout << adjList[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}