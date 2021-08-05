#include<iostream>
#include<vector>
using namespace std;



// optimized

bool isSafe(vector<vector<int>>&mat, int row, int col, int n, vector<int>&rCount, vector<int>&lowerDia, vector<int>&upperDia)
{
	if (rCount[row] == 1)
	{
		return false;
	}
	if (lowerDia[row + col] == 1)
	{
		return false;
	}
	if (upperDia[n - 1 + col - row] == 1)
	{
		return false;
	}
	return true;
}

bool solveNQueens(vector<vector<int>>&mat, int n, int col, vector<int>&rCount, vector<int>&lowerDia, vector<int>&upperDia)
{
	if (col == n)
	{
		// all columns filled, print the board
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}


	for (int row = 0; row < n; row++)
	{
		if (isSafe(mat, row, col, n, rCount, lowerDia, upperDia))
		{
			mat[row][col] = 1;
			rCount[row] = 1;
			lowerDia[row + col] = 1;
			upperDia[n - 1 + col - row] = 1;
			if (solveNQueens(mat, n, col + 1, rCount, lowerDia, upperDia) == true)
			{
				return true;
			}
			// backtrack
			rCount[row] = 0;
			lowerDia[row + col] = 0;
			upperDia[n - 1 + col - row] = 0;
			mat[row][col] = 0;

		}
	}
	return false;

}





// regular nQueens, isSafe not optimized;
bool isSafe(vector<vector<int>>&mat, int row, int col, int n)
{
	int i, j;
	// checking with in the row, i.e row constant and col changes
	i = col;
	while (i >= 0)
	{
		if (mat[row][i] == 1)
		{
			return false;
		}
		i--;
	}

	// checking left upper diagonal, i.e row and col both changes
	i = row;
	j = col;
	while (i >= 0 && j >= 0)
	{
		if (mat[i][j] == 1)
		{
			return false;
		}
		i--;
		j--;
	}

	// checking left down diagonal, i.e row and col both changes
	i = row;
	j = col;
	while (i > n && j >= 0)
	{
		if (mat[i][j] == 1)
		{
			return false;
		}
		i++;
		j--;
	}

	// if any of the above conditions doesnt return false, then the position is safe
	return true;

}


bool solveNQueens(vector<vector<int>>&mat, int n, int col)
{
	if (col == n)
	{
		// all columns filled, print the board
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}


	for (int row = 0; row < n; row++)
	{
		if (isSafe(mat, row, col, n))
		{
			mat[row][col] = 1;
			if (solveNQueens(mat, n, col + 1) == true)
			{
				return true;
			}
			mat[row][col] = 0;

		}
	}
	return false;

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<vector<int>>mat(n, vector<int>(n, 0)); //nxn matrix (board)
	int col = 0;
	vector<int>rCount(n, 0);
	vector<int>upperDia(2 * n - 1, 0);
	vector<int>lowerDia(2 * n - 1, 0);
	// solveNQueens(mat, n, col); // not optimized
	solveNQueens(mat, n, col, rCount, lowerDia, upperDia);  // optimized

	return 0;
}