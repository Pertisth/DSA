#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<vector<int>>&dp, vector<int>&arr, int n, int sum, int idx)
{
	if (idx >= n)
	{
		return false;
	}
	if (dp[idx][currSum] != -1)
	{
		return true;
	}
	dp[idx + 1][currSum + arr[idx]] = canPartition(dp, arr, n, sum, idx + 1, currSum + arr[idx]) ? 1 : 0;

	dp[idx + 1][currSum] = canPartition(dp, arr, n, sum, idx + 1, currSum) ? 1 : 0;
	return dp[idx][currSum] == 1 ? true : false;

}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>arr{1, 5, 11, 5};
	int maxSum = 22;
	int sum = maxSum / 2;
	int currSum = 0;
	int n = 4;
	vector<vector<int>>dp(n + 1, vector<int>(sum + 1, -1));
	cout <<  canPartition(dp, arr, n, sum, 0, currSum);

	return 0;

}
