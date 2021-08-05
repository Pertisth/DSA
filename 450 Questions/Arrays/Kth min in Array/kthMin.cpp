#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int partition(vector<int>&arr, int low, int high)
{
	int pivot = arr[low];
	int i = low - 1;
	int j = high + 1;
	while (true)
	{
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);
		if (i >= j)
		{
			return j;
		}
		swap(arr[i], arr[j]);
	}
}

void quickSort(vector<int>&arr, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}


int kthSmall(vector<int>arr, int k)
{
	quickSort(arr, 0, arr.size() - 1);
	return arr[k - 1];

}

int kthLargest(vector<int>arr, int k)
{
	quickSort(arr, 0, arr.size() - 1);
	return arr[arr.size() - k];

}


int kthLargestHeap(vector<int>&arr, int k)
{
	priority_queue<int, vector<int>, greater<int>>minHeap(arr.begin(), arr.begin() + k);

	for (int i = k; i < arr.size(); i++)
	{
		if (arr[i] > minHeap.top())
		{
			minHeap.pop();
			minHeap.push(arr[i]);
		}
	}
	while (!minHeap.size() == 1)
	{
		minHeap.pop();
	}
	return minHeap.top();

}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int>arr;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		arr.push_back(ele);
	}
	cout << kthSmall(arr, k) << endl;;
	cout << kthLargestHeap(arr, k) << endl;

	return 0;
}