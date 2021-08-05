#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void nextPermutation(vector<int>&arr)
{
	int n = arr.size();
	int i;
	int idx1;
	int idx2;
	for (i = n - 2; i >= 0; i--)
	{
		if (arr[i] < arr[i + 1])
		{
			idx1 = i;
			break;
		}
	}
	if (i < 0) // all are in descending order
	{
		reverse(arr.begin(), arr.end());
	}
	else
	{
		int j = n - 1;
		while (j > i)
		{
			if (arr[j] > arr[i])
			{
				idx2 = j;
				break;
			}
		}
		swap(arr[i], arr[j]);
		reverse(arr.begin() + idx1 + 1, arr.end());
	}


	//print the next permutation
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
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
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	nextPermutation(arr);
	return 0;
}