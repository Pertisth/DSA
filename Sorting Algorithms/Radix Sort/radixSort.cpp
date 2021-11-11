#include<iostream>
#include<vector>
using namespace std;



void countSort(vector<int>&arr, int n, int exp);
void radixSort(vector<int>&arr, int n)
{
	int maxi = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		maxi = max(maxi, arr[i]);
	}

	for (int i = 1; maxi / i > 0 ; i = i * 10)
	{
		countSort(arr, n, i);
	}

}

void countSort(vector<int>&arr, int n, int exp)
{
	vector<int>count(10, 0);
	for (int i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		count[i] = count[i] + count[i - 1];
	}
	vector<int>output(n);
	for (int i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = output[i];
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
	radixSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}