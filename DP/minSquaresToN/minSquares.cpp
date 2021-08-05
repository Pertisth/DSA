#include<iostream>
using namespace std;

// recursive solution
int minSquares(int n)
{
	int res = n;
	for (int i = 1; i <= n; i++)
	{
		int temp = i * i;
		if (temp > n)
		{
			break;
		}
		res = min(res, 1 + minSquares(n - temp));
	}
	return res;
}


// optimization with dp
int minSquaresDP(int n, int dp[])
{
	if (dp[n] != 0)
	{
		return dp[n];
	}
	int res = n;
	for (int i = 1; i <= n; i++)
	{
		int temp = i * i;
		if (temp > n)
		{
			break;
		}
		res = min(res, 1 + minSquaresDP(n - temp, dp));
		dp[n] = res;
	}
	return dp[n];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	// cout << minSquares(n);
	int dp[n + 1] = {0};
	cout << minSquaresDP(n, dp);
	return 0;
}