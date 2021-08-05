#include<iostream>
#include<vector>
using namespace std;

bool isPossible(int row, int col, int c, vector<vector<int>>&board)
{
	for (int i = 0; i <= 8; i++)
	{
		if (board[row][i] == c)
		{
			return false;
		}
		if (board[i][col] == c)
		{
			return false;
		}

		if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
		{
			return false;
		}
	}
	return true;
}

bool solve(vector<vector<int>>& board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 0)
			{
				for (int c = 1; c <= 9; c++)
				{
					if (isPossible(i, j, c, board))
					{
						board[i][j] = c;

						if (solve(board))
						{
							return true;
						}
						else
						{
							board[i][j] = 0;
						}
					}
				}
				return false;
			}
		}
	}
	return true;
}



void solveSoduku(vector<vector<int>>&board)
{
	solve(board);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<int>>board;
	for (int i = 0; i < 9; i++)
	{
		vector<int>v;
		for (int j = 0; j < 9; j++)
		{
			int ele;
			cin >> ele;
			v.push_back(ele);
		}
		board.push_back(v);
	}


	solveSoduku(board);

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


