#include<iostream>
#include<vector>
using namespace std;


int searchUtil(vector<int>&arr, int x, int low, int high)
{
	if (low > high)
	{
		return -1;
	}
	int mid = (low + high) / 2;
	if (arr[mid] == x)
	{
		return mid;
	}
	if (arr[low] <= arr[mid])
	{
		if (x >= arr[low] && x <= arr[mid])
		{
			return searchUtil(arr, x, low, mid - 1);
		}
		return searchUtil(arr, x, mid + 1, high);
	}
	if (x >= arr[mid] && x <= arr[high])
	{
		return searchUtil(arr, x, mid + 1, high);
	}
	return searchUtil(arr, x, low, mid - 1);
}


int searchInRotatedSortedArray(vector<int>&arr, int target)
{
	int n = arr.size();
	return searchUtil(arr, target, 0, n - 1);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>arr;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		arr.push_back(ele);
	}
	int target;
	cin >> target;

	int idx = searchInRotatedSortedArray(arr, target);
	cout << "Index of the target is : " << idx;

	return 0;
}