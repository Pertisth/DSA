#include<iostream>
#include<vector>
using namespace std;



// brute force solution O(2^n)
int knapSack(vector<int>&values, vector<int>&weights, int w, int idx, int weight)
{
	if (weight > w)
	{
		return INT_MIN;
	}
	if (idx == values.size())
	{
		return 0;
	}
	int pick = values[idx] + knapSack(values, weights, w, idx + 1, weight + weights[idx]);
	int notPick = knapSack(values, weights, w, idx + 1, weight);
	return max(pick, notPick);
}


// dp
int knapSackDP(vector<int>&values, vector<int>&weights, int w, int idx, int weight, vector<vector<int>>&dp)
{
	if (dp[idx][weight] != -1)
	{
		return dp[idx][weight];
	}
	if (weight > w)
	{
		return INT_MIN;
	}
	if (idx == values.size())
	{
		return 0;
	}

	int pick = values[idx] + knapSackDP(values, weights, w, idx + 1, weight + weights[idx], dp);
	int notPick = knapSackDP(values, weights, w, idx + 1, weight, dp);
	dp[idx][weight] = max(pick, notPick);
	return dp[idx][weight];
}




int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>weights;
	vector<int>values;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		values.push_back(ele);
	}
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		weights.push_back(ele);
	}
	int w;
	cin >> w;
	// cout << knapSack(values, weights, w, 0, 0 );
	vector<vector<int>>dp (1000, vector<int>(1000, -1));
	cout << knapSackDP(values, weights, w, 0, 0 , dp);
	return 0;
}