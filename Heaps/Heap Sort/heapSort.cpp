#include<iostream>
#include<vector>
using namespace std;


void maxHeapify(int i, int size, vector<int>&arr)
{
	int lt = 2 * i + 1; // left child
	int rt = 2 * i + 2; // right child
	int largest = i;
	if (lt < size && arr[lt] > arr[i])
	{
		largest = lt;
	}
	if (rt < size && arr[rt] > arr[largest])
	{
		largest = rt;
	}
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		maxHeapify(largest, size, arr);
	}
}

void buildHeap(vector<int>&arr, int n)
{
	for (int i = n - 2 / 2; i >= 0; i--)
	{
		maxHeapify(i, n, arr);
	}
}

void heapSort(vector<int>&arr)
{
	int n = arr.size();
	buildHeap(arr, n);
	int i = n;
	while (i >= 1)
	{
		swap(arr[0], arr[i - 1]);
		i--;
		maxHeapify(0, i, arr);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		arr.push_back(ele);
	}
	heapSort(arr);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}