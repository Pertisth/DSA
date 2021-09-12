#include<iostream>
#include<vector>
using namespace std;


int solve(int arr[], int n, int k, vector<int>&dp)
{
	if (n == 0)
	{
		return 0;
	}
	if (dp[n] != -1)
	{
		return dp[n];
	}
	int mini = INT_MAX;
	for (int i = 1; i <= k; i++)
	{
		if (n - i >= 0)
		{
			mini = min(mini, solve(arr, n - i, k, dp) + abs(arr[n] - arr[n - i]));
		}
	}
	return dp[n] = mini;
}


int main()
{
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int>dp(n + 1, -1);
	cout << solve(arr, n - 1, k, dp);
	return 0;
}