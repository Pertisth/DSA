#include<iostream>
#include<vector>
using namespace std;

void countSort(vector<int>&arr, int n, int k)
{
	vector<int>count(k, 0);
	for (int i = 0; i < n; i++)
	{
		count[arr[i]]++;
	}

	for (int i = 1; i < k; i++)
	{
		count[i] = count[i - 1] + count[i];
	}
	vector<int>output(n, 0);
	for (int i = n - 1; i >= 0; i--)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	countSort(arr, n, k);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}