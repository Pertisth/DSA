#include<iostream>
#include<vector>
using namespace std;


// dp tabulation
int editDistanceDP(string s1, string s2, int n, int m)
{
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	// filling first column (base case)
	for (int i = 0; i < n; i++)
	{
		dp[i][0] = i;
	}
	// filling first row (base case)
	for (int j = 0; j < m; j++)
	{
		dp[0][j] = j;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = 1 + min(
				               min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]
				           );
			}
		}
	}
	return dp[n][m];

}








// recursive solution
int editDistance(string s1, string s2, int n, int m)
{
	if (n == 0)
	{
		return m;
	}
	if (m == 0)
	{
		return n;
	}
	if (s1[n - 1] == s2[m - 1])
	{
		return 0 + editDistance(s1, s2, n - 1, m - 1);
	}
	else
	{
		return 1 + min(
		           min(editDistance(s1, s2, n, m - 1), editDistance(s1, s2, n - 1, m)),
		           editDistance(s1, s2, n - 1, m - 1)
		       );
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s1;
	string s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();
	// cout << editDistance(s1, s2, n, m); // recursive solution


	// dp tabulation

	cout << editDistanceDP(s1, s2, n, m);

	return 0;
}