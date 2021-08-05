#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> slidingWindowMax(vector<int>&arr, int n, int k)
{
	deque<int>que;
	vector<int>res;
	for (int i = 0; i < n; i++)
	{
		if (!que.empty() && que.front() == i - k)
		{
			que.pop_front();
		}
		while (!que.empty() && arr[que.back()] <= arr[i])
		{
			que.pop_back();
		}
		que.push_back(i);
		if (i >= k - 1)
		{
			res.push_back(arr[que.front()]);
		}

	}
	return res;
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
		cin >> arr[i] ;
	}
	int k;
	cin >> k;
	vector<int>res = slidingWindowMax(arr, n, k);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}