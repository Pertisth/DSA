#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> firstNegativeOfWindow(vector<int>&arr, int k)
{
	deque<int>dq;
	vector<int>res;
	int n = arr.size();
	int i = 0;
	int j = 0;
	while (j < n)
	{
		if (arr[j] < 0)
		{
			dq.push_back(j);
		}
		if (j - i + 1 == k)
		{
			int val = 0;
			if (dq.empty() == false)
			{
				val = arr[dq.front()];
			}
			res.push_back(val);
			if (dq.front() == i)
			{
				dq.pop_front();
			}
			i++;
		}
		j++;
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
		cin >> arr[i];
	}
	int k;
	cin >> k;
	vector<int>res = firstNegativeOfWindow(arr, k);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}