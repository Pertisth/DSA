#include<iostream>
#include<vector>
using namespace std;


bool isPossible(vector<int>&arr, int barrier, int k)
{
	int alloStudents = 1;
	int pages = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > barrier)
		{
			return false;
		}
		if (arr[i] + pages > barrier)
		{
			alloStudents++;
			pages = arr[i];
		}
		else
		{
			pages = pages + arr[i];
		}
	}
	if (alloStudents > k)
	{
		return false;
	}
	return true;
}



int allocateMinPages(vector<int>&arr, int k)
{
	int totalPages = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		totalPages = totalPages + arr[i];
	}
	int n = arr.size();
	int low = arr[n - 1];
	int high = totalPages;


	int res = INT_MAX;
	while (low <= high)
	{
		int mid = (low + high) >> 1;
		if (isPossible(arr, mid, k))
		{
			res = mid;
			high = mid - 1;

		}
		else
		{
			low = mid + 1;
		}

	}
	return res;
}


int main()
{
#ifndef ONILINE_JUDGE
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
	int students;
	cin >> students;
	cout << allocateMinPages(arr, students);
	return 0;
}