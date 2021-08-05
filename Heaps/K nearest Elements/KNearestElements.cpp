#include<iostream>
#include<queue>
#include<utility>
using namespace std;


void printKNearestElements(int arr[], int n, int x, int k)
{
	priority_queue<pair<int, int>>heap;
	for (int i = 0; i < k; i++)
	{
		heap.push({abs(x - arr[i]), i});
	}

	for (int i = k; i < n; i++)
	{
		int diff = abs(x - arr[i]);
		if (heap.top().first > diff)
		{
			heap.pop();
			heap.push({diff, i});
		}
	}

	while (!heap.empty())
	{
		cout << arr[heap.top().second] << " ";
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
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int x;
	cin >> x;
	int k;
	cin >> k;
	printKNearestElements(arr, n, x, k);

	return 0;
}