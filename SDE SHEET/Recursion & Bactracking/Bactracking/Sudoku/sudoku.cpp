#include<iostream>
#include<vector>
using namespace std;


bool isSafe(vector<vector<int>>&board, int row, int col, int val)
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i][col] == val)
		{
			return false;
		}
		if (board[row][i] == val)
		{
			return false;
		}
		if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
		{
			return false;
		}
	}
	return true;
}


bool solve(vector<vector<int>>&board)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
			{
				for (int k = 1; k <= 9; k++)
				{
					if (isSafe(board, i, j, k) == true)
					{
						board[i][j] = k;
						if (solve(board))
						{
							return true;
						}
						board[i][j] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}



void solveBoard(vector<vector<int>>&board)
{
	solve(board);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<int>>board(9, vector<int>(9, 0));

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int ele;
			cin >> ele;
			board[i][j] = ele;
		}
	}
	solveBoard(board);

	// print solved board
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}