#include<bits/stdc++.h>
using namespace std;


vector<int> printMaxOfKWindow(vector<int>&arr, int k)
{
	vector<int>res;
	deque<int>dq;
	for (int i = 0; i < k; i++)
	{
		while (!dq.empty() && arr[dq.front()] <= arr[i])
		{
			dq.pop_front();
		}
		dq.push_back(i);
	}

	for (int i = k; i < arr.size(); i++)
	{
		res.push_back(arr[dq.front()]);
		while (!dq.empty() && dq.front() <= i - k)
		{
			dq.pop_front();
		}
		while (!dq.empty() && arr[dq.back()] <= arr[i])
		{
			dq.pop_back();
		}
		dq.push_back(i);
	}
	res.push_back(arr[dq.front()]);
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
	int k;
	cin >> k;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int>res = printMaxOfKWindow(arr, k);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}