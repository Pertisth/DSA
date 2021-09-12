#include<iostream>
#include<vector>
using namespace std;

int hoaresPartition(vector<int>&arr, int low, int high)
{
	int i = low - 1;
	int j = high + 1;
	int pivot = arr[low];
	while (true)
	{
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);
		if (i >= j)
		{
			return j;
		}
		swap(arr[i], arr[j]);
	}
}


void quickSort(vector<int>&arr, int low, int high)
{
	if (low < high)
	{
		int pivot = hoaresPartition(arr, low, high);
		quickSort(arr, low, pivot);
		quickSort(arr, pivot + 1, high);
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
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}