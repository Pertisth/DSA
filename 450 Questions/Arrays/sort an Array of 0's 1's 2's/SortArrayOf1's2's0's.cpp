#include<iostream>
#include<vector>
using namespace std;




void sortArr(vector<int>&arr)
{
	int low = 0;
	int mid = 0;
	int high = arr.size() - 1;
	while (mid <= high)
	{
		if (arr[mid] == 0)
		{
			swap(arr[mid], arr[low]);
			mid++;
			low++;
		}
		else if (arr[mid] == 1)
		{
			mid++;
		}
		else if (arr[mid] == 2)
		{
			swap(arr[mid], arr[high]);
			high--;
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
	vector<int>arr;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		arr.push_back(ele);
	}

	sortArr(arr);
	cout << "After Sorting : ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}