#include<iostream>
#include<vector>
using namespace std;

void subSequence(string s, int i, string res)
{
	if (i == s.length())
	{
		cout << res << " ";
		return;
	}
	subSequence(s, i + 1, res);
	subSequence(s, i + 1, res + s[i]);
}






int LCS(string s1, string s2, int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 0;
	}
	if (s1[m - 1] == s2[n - 1])
	{
		return 1 + LCS(s1, s2, m - 1, n - 1);
	}
	else
	{
		return max(LCS(s1, s2, m, n - 1), LCS(s1, s2, m - 1, n));
	}
}

// memoization based solution
int lcsDP1(string s1, string s2, int m, int n, vector<vector<int>>&dp)
{
	if (dp[m][n] != -1)
	{
		return dp[m][n];
	}
	if (m == 0 || n == 0)
	{
		return dp[m][n] = 0;
	}
	else
	{
		if (s1[m - 1] == s2[n - 1])
		{
			dp[m][n] = 1 + lcsDP1(s1, s2, m - 1, n - 1, dp);
		}
		else
		{
			dp[m][n] = max(lcsDP1(s1, s2, m - 1, n, dp), lcsDP1(s1, s2, m, n - 1, dp));
		}
	}
	return dp[m][n];
}


// tabulation method (iterative)
int lcsDp2(string s1, string s2)
{
	// fill first column and first row with 0's, **already Filled**
	int m = s1.length();
	int n = s2.length();
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
	int i;
	int j;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (s1[i] == s2[j])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
			}
		}
	}
	return dp[i - 1][j - 1];
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
	int m = s1.length();
	int n = s2.length();
	// cout << LCS(s1, s2, m, n);


	// 2nd method
	// vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
	// cout << lcsDP1(s1, s2, m, n, dp);


	// 3rd method

	cout << lcsDp2(s1, s2);
	return 0;
}