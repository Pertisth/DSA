#include<iostream>
#include<vector>
using namespace std;

int countPaths(int n, int m)
{
	if (n == 1 || m == 1)
	{
		return 1;
	}
	return countPaths(n - 1, m) + countPaths(n, m - 1);
}

int countPathsDP(int n, int m)
{
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));

	// first row and first column is 1 because only one way to reach
	for (int i = 0; i < n; i++)
	{
		dp[i][0] = 1;
	}
	for (int j = 0; j < m; j++)
	{
		dp[0][j] = 1;
	}


	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[n - 1][m - 1];

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	cout << countPathsDP(n, m);
	return 0;
}