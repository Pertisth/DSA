#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr, int low, int mid, int high, vector<int>&temp)
{
	int k = low;
	int i = low;
	int j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			temp[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i <= mid)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}
	for (int i = low; i <= high; i++)
	{
		arr[i] = temp[i];
	}
}

void mergeSort(vector<int>&arr, int low, int high, vector<int>&temp)
{
	if (low < high)
	{
		int mid = (low + high) >> 1;
		mergeSort(arr, low, mid, temp);
		mergeSort(arr, mid + 1, high, temp);
		merge(arr, low, mid, high, temp);
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
	vector<int>temp(n);
	mergeSort(arr, 0, n - 1, temp);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}