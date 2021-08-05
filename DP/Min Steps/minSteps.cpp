#include<iostream>
#include<vector>
using namespace std;


int minSteps(int n)   // navie solution
{
	if (n <= 1)
	{
		return 0;
	}
	int x = minSteps(n - 1);
	int y = INT_MAX;
	if (n % 2 == 0)
	{
		y = minSteps(n / 2);
	}
	int z = INT_MAX;
	if (n % 3 == 0)
	{
		z = minSteps(n / 3);
	}

	return (min(x, min(y, z)) + 1);

}


int minStepsUtil(int n, vector<int>&arr)
{
	if (n <= 1)
	{
		return 0;
	}
	if (arr[n] != -1)
	{
		return arr[n];
	}
	int x = minStepsUtil(n - 1, arr);
	int y = INT_MAX;
	if (n % 2 == 0)
	{
		y = minStepsUtil(n / 2, arr);
	}
	int z = INT_MAX;
	if (n % 3 == 0)
	{
		z = minStepsUtil(n / 3, arr);
	}
	arr[n] = min(x, min(y, z)) + 1;
	return arr[n];
}


int minSteps2(int n)  // memoization
{
	vector<int>arr(n + 1, -1);
	return minStepsUtil(n, arr);
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	cout << minSteps2(n);
	return 0;
}