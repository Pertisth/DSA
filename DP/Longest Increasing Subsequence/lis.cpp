#include<iostream>
#include<vector>
using namespace std;

// RECURSION
int lis(vector<int>&arr, int idx, int prev)
{
	if (idx == arr.size())
	{
		return 0;
	}
	int notPick = lis(arr, idx + 1, prev);
	int pick = 0;
	if (arr[idx] > prev)
	{
		pick = 1 + lis(arr, idx + 1, arr[idx]);
	}
	return max(pick, notPick);

}


// dp
int lisDP(vector<int>&arr)
{
	int n = arr.size();
	vector<int>dp(n, 0);

	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int res = dp[0];
	for (int i = 1; i < n; i++)
	{
		if (res < dp[i])
		{
			res = max(res, dp[i]);
		}
	}
	return res;
}


// binary search

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>arr;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		arr.push_back(ele);
	}
	cout << lis(arr, 0, INT_MIN);

	// cout << lisDP(arr);
	return 0;
}