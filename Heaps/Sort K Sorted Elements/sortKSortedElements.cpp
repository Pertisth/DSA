#include<iostream>
#include<queue>
using namespace std;

void sortKSortedElements(vector<int>&arr, int k)
{
	int n = arr.size();
	priority_queue<int, vector<int>, greater<int>>heap;
	for (int i = 0; i <= k; i++)
	{
		heap.push(arr[i]);
	}
	int idx = 0;
	for (int i = k + 1; i < n; i++)
	{
		arr[idx++] = heap.top();
		heap.pop();
		heap.push(arr[i]);
	}
	while (!heap.empty())
	{
		arr[idx++] = heap.top();
		heap.pop();
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
	int k;
	cin >> k;
	sortKSortedElements(arr, k);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}