#include<iostream>
#include<vector>
using namespace std;


void spiralTraversal(vector<vector<int>>&matrix, int r, int c)
{
	int top = 0;   // top of matrix
	int left = 0;  // left of matrix
	int bottom = r - 1; // bottom of matrix
	int right = c - 1; // right of matrix

	while (top <= bottom && left <= right)
	{
		for (int i = left; i <= right; i++)
		{
			cout << matrix[top][i] << " ";
		}
		top++;
		for (int i = top; i <= bottom; i++)
		{
			cout << matrix[i][right] << " ";
		}
		right--;
		for (int i = right; i >= left; i--)
		{
			cout << matrix[bottom][i] << " ";
		}
		bottom--;
		for (int i = bottom; i >= top; i--)
		{
			cout << matrix[i][left] << " ";
		}
		left++;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int r, c;
	cin >> r >> c;
	vector<vector<int>>matrix(r, vector<int>(c));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> matrix[i][j];
		}
	}

	spiralTraversal(matrix, r, c);

	return 0;
}