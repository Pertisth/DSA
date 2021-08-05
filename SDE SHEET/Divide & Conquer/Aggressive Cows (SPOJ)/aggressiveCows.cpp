#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool isPossibleToPlaceCows(vector<int>&arr, int cows, int dist)
{
	int c = arr[0];
	int count = 1;
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] - c >= dist)
		{
			count++;
			c = arr[i];
		}
	}
	if (count == cows)
	{
		return true;
	}
	return false;
}




//largest min distance
int aggressiveCows(vector<int>&arr, int cows)
{
	int n = arr.size();
	int low = 1;
	int high = arr[n - 1] - arr[0];
	int res = 0;
	while (low <= high)
	{
		int mid = (low + high) >> 1;
		if (isPossibleToPlaceCows(arr, cows, mid))
		{
			res = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}

	}
	return res;
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
	int cows;
	cin >> cows;
	sort(arr.begin(), arr.end());
	cout << aggressiveCows(arr, cows);
	return 0;
}