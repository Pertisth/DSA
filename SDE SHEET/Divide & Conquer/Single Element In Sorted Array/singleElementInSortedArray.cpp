#include<iostream>
#include<vector>
using namespace std;


int findSingleElement(vector<int>&arr, int n)  // O(logn)
{
	int low = 0;
	int high = n - 2;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == arr[mid ^ 1])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return arr[low];
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
	cout << findSingleElement(arr, n);

	return 0;
}