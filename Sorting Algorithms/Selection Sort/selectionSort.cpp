#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>&arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIdx = i;
		for (int j = i + 1 ; j < n; j++)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
		}
		swap(arr[i], arr[minIdx]);
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	selectionSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}