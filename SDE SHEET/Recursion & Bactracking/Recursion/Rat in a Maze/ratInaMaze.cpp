#include<iostream>
#include<vector>
using namespace std;

// same function but removed repeated code
void findPathUtilNew(int row, int col, vector<vector<int>>&maze, vector<vector<int>>&vis, string path, int n, int di[], int dj[])
{
	if (row == n - 1 && col == n - 1)
	{
		cout << path << endl;
		return;
	}
	string dir = "DLRU";
	for (int i = 0; i < 4; i++)
	{
		int nextRow = row + di[i];
		int nextCol = col + dj[i];
		if (nextRow >= 0 && nextCol >= 0 && nextCol < n && nextRow < n && vis[nextRow][nextCol] == 0 && maze[nextRow][nextCol] == 1)
		{
			vis[row][col] = 1;
			findPathUtilNew(nextRow, nextCol, maze, vis, path + dir[i], n, di, dj);
			vis[row][col] = 0;
		}
	}
}


void findPathUtil(int row, int col, vector<vector<int>>&maze, vector<vector<int>>&vis, string path, int n)
{
	if (row == n - 1 && col == n - 1)
	{
		cout << path << endl;
		return;
	}
	// down
	if (row + 1 < n && vis[row + 1][col] == 0 && maze[row + 1][col] == 1)
	{
		vis[row][col] = 1;
		findPathUtil(row + 1, col, maze, vis, path + "D", n);
		vis[row][col] = 0;
	}

	//left
	if (col - 1 >= 0 && vis[row][col - 1] == 0 && maze[row][col - 1] == 1)
	{
		vis[row][col] = 1;
		findPathUtil(row, col - 1, maze, vis, path + "L", n);
		vis[row][col] = 0;
	}

	//right
	if (col + 1 < n && vis[row][col + 1] == 0 && maze[row][col + 1] == 1)
	{
		vis[row][col] = 1;
		findPathUtil(row, col + 1, maze, vis, path + "R", n);
		vis[row][col] = 0;
	}

	//up
	if (row - 1 >= 0 && vis[row - 1][col] == 0 && maze[row - 1][col] == 1)
	{
		vis[row][col] = 1;
		findPathUtil(row - 1, col, maze, vis, path + "U", n);
		vis[row][col] = 0;
	}


}


void findPath(vector<vector<int>>&maze, int n)
{
	vector<vector<int>>vis(n, vector<int>(n, 0));
	string path = "";
	int di[] = {1, 0, 0, -1};
	int dj[] = {0, -1, 1, 0};
	vis[0][0] = 1;
	findPathUtilNew(0, 0, maze, vis, path, n, di, dj);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<int>>maze{
		{1, 0, 0, 0},
		{1, 1, 0, 1},
		{1, 1, 0, 0},
		{0, 1, 1, 1}
	};
	findPath(maze, 4);
	return 0;
}