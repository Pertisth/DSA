#include<iostream>
#include<vector>
using namespace std;

// recursion
int coinChangeCountCombinations(vector<int>&arr, int sum, int idx)
{
	if (idx == arr.size() || sum < 0)
	{
		return 0;
	}
	if (sum == 0)
	{
		return 1;
	}
	int pick = coinChangeCountCombinations(arr, sum - arr[idx], idx);
	int notPick = coinChangeCountCombinations(arr, sum, idx + 1);
	return pick + notPick;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int sum;
	cin >> sum;
	cout << coinChangeCountCombinations(arr, sum, 0);
	return 0;
}