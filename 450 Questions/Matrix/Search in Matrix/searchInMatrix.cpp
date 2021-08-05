#include<iostream>
#include<vector>

using namespace std;

bool searchInMatrix(vector<vector<int>>&matrix, int target)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] == target)
			{
				return true;
			}
		}
	}
	return false;
}

bool searchInMatrixEfficient(vector<vector<int>>&matrix, int target)
{
	int row = matrix.size();
	int col = matrix[0].size();

	int i = 0;//     }====> pointing at the top on last column in matrix
	int j = col - 1; // }====>

	while (i < row && j >= 0)
	{
		if (matrix[i][j] == target)
		{
			return true;
		}
		else if (matrix[i][j] > target)
		{
			j--;
		}
		else
		{
			i++;
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

	int r, c;
	cin >> r >> c;
	int target;
	cin >> target;
	vector<vector<int>>matrix(r, vector<int>(c));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> matrix[i][j];
		}
	}

	if (searchInMatrixEfficient(matrix, target))
	{
		cout << "Found" << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
	return 0;
}