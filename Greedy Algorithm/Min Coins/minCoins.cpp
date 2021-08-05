#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


int minCoins(vector<int>&arr, int x)
{
	sort(arr.begin(), arr.end(), greater<int>());
	int res = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] <= x)
		{
			int c = floor(x / arr[i]);
			res = res + c;
			x = x - c * arr[i];
		}
		if ( x == 0)
		{
			break;
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
	int target;
	cin >> target;
	cout << minCoins(arr, target);
	return 0;
}