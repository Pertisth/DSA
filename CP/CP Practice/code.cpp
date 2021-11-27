#include<iostream>
#include<vector>
using namespace std;

int findMaxPairs(vector<int>&arr, int n)
{
	int maxi = 0;
	vector<int>vis(n, 0);
	for (int i = 0; i < n - 1; i++)
	{
		int sum = arr[i] + arr[i + 1];
		if (sum % 2 == 0 && vis[i] == 0)
		{
			vis[i] = 1;
			vis[i + 1] = 1;
			maxi++;
		}
	}
	if (vis[0] == 0 && vis[n - 1] == 0)
	{
		int sum = arr[0] + arr[n - 1];
		if (sum % 2 == 0)
		{
			maxi++;
		}
	}
	return maxi;
}

int binaryToDecimal(string &str)
{
	int num = 0;
	int base = 1;

	int n = str.length();
	for (int i = n - 1; i >= 0; i--)
	{
		if (str[i] == '1')
		{
			num = num + base;
		}
		base = base * 2;
	}
	return num;
}

int countOperations(int num)
{
	if (num <= 0)
	{
		return 0;
	}
	if (num % 2 == 0)
	{
		return 1 + countOperations(num / 2);
	}
	return 1 + countOperations(num - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string str;
	cin >> str;
	int num = binaryToDecimal(str);
	cout << countOperations(num);
	return 0;
}