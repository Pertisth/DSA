#include<iostream>
#include<vector>
using namespace std;


int smallerThanEqualToMid(vector<int>&arr, int x)
{
	int low = 0;
	int high = arr.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) >> 1;
		if (arr[mid] <= x)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return low;
}


int medianOfMatrix(vector<vector<int>>&arr)
{

	int low = INT_MIN;
	int high = INT_MAX;
	int n = arr.size();
	int m = arr[0].size();

	while (low <= high)
	{
		int mid = (low + high) >> 1;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			count = count + smallerThanEqualToMid(arr[i], mid);
		}
		if (count <= (n * m) >> 1)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return low;

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<vector<int>>matrix;
	for (int i = 0; i < n; i++)
	{
		vector<int>a;
		for (int j = 0; j < n; j++)
		{
			int ele;
			cin >> ele;
			a.push_back(ele);
		}
		matrix.push_back(a);
	}
	cout << medianOfMatrix(matrix);
	return 0;
}


// int n = arr.size();
// 	for (int i = 0; i < n; i++)
// 	{
// 		vector<int>a;
// 		for (int j = 0; j < n; j++)
// 		{
// 			cout << arr[i][j] << " ";
// 		}
// 		cout << endl;
// 	}