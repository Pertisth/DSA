#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insertionSort(vector<int>&arr)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void bucketSort(vector<int>&arr, int n, int k)
{
	int maxi = *max_element(arr.begin(), arr.end());
	maxi++;
	vector<int>buckets[k];
	for (int i = 0; i < n; i++)
	{
		int bktIdx = (k * arr[i]) / maxi;
		buckets[bktIdx].push_back(arr[i]);
	}
	for (int i = 0; i < k; i++)
	{
		insertionSort(buckets[i]);
	}
	int i = 0;
	for (auto bkts : buckets)
	{
		for (auto x : bkts)
		{
			arr[i] = x;
			i++;
		}
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
	int k;
	cin >> k;
	bucketSort(arr, n, k);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}