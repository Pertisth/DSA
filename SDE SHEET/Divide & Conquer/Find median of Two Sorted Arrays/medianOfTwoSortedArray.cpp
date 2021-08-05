#include<iostream>
#include<vector>
#include<limits>
using namespace std;


double findMedian(vector<int>&arr1, vector<int>&arr2, int n, int m)
{
	if (m < n)
	{
		return findMedian(arr2, arr1, m, n);
	}


	int low = 0;
	int high = n;

	while (low <= high)
	{
		int mid1 = (low + high) >> 1;
		int mid2 = ((n + m + 1) >> 1) - mid1;

		int l1 = (mid1 == 0) ? INT_MIN : arr1[mid1 - 1];
		int l2 = (mid2 == 0) ? INT_MIN : arr2[mid2 - 1];

		int r1 = (mid1 == n) ? INT_MAX : arr1[mid1];
		int r2 = (mid1 == m) ? INT_MAX : arr2[mid2];

		if (l1 <= r2 && l2 <= r1)
		{
			if ((n + m) % 2 == 0)
			{
				return (max(l1, l2) + min(r1, r2)) / 2;
			}
			else
			{
				return min(r1, r2);
			}
		}
		else if (l1 > r2)
		{
			high = mid1 - 1;
		}
		else
		{
			low = mid1 + 1;
		}


	}
	return 0.0;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr1, arr2;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		arr1.push_back(ele);
	}
	for (int i = 0; i < m; i++)
	{
		int ele;
		cin >> ele;
		arr2.push_back(ele);
	}

	double res = findMedian(arr1, arr2, n, m);
	cout << res;
	return 0;
}