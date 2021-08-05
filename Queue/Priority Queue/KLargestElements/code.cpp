#include<iostream>
#include<queue>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	int k;
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	priority_queue<int, vector<int>, greater<int>>pq(arr, arr + k);
	for (int i = k; i < n; i++)
	{
		if (arr[i] > pq.top())
		{
			pq.pop();
			pq.push(arr[i]);
		}
	}

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}