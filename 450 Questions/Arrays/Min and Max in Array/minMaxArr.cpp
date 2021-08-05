#include<iostream>
#include<utility>
using namespace std;


pair<int, int> minMaxEfficient(int arr[], int n)    /// less number of comparisions
{
	int min;
	int max;
	if (n == 1)
	{
		min = arr[0];
		max = arr[0];
	}
	else
	{
		if (arr[0] < arr[1])
		{
			min = arr[0];
			max = arr[1];
		}
		else
		{
			min = arr[1];
			max = arr[0];
		}
	}
	for (int i = 2; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
		else if (max < arr[i])
		{
			max = arr[i];
		}
	}
	pair<int, int>p = make_pair(min, max);
	return p;
}


pair<int, int> minMax(int arr[], int n)
{
	int min = INT_MAX;
	int max = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
		else if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	pair<int, int>p = make_pair(min, max);
	return p;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	pair<int, int>p = minMaxEfficient(arr, n);


	cout << "Min in array is : " << p.first << endl;
	cout << "Max in array is : " << p.second << endl;
	return 0;
}