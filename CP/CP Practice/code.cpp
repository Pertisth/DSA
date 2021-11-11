#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minimumMulitplications(int start, int end, vector<int>&arr)
{
	int n = arr.size();
	queue<pair<int, int>>que;
	que.push({start, 0});

	vector<int>vis(100001, -1);
	while (!que.empty())
	{
		int currVal = que.front().first;
		int mul = que.front().second;
		que.pop();
		if (currVal == end)
		{
			return mul;
		}

		for (int i = 0; i < n; i++)
		{
			int multipliedVal = (currVal * arr[i]) % 100000;
			if (vis[multipliedVal] == -1)
			{
				que.push({multipliedVal, mul + 1});
			}
		}
	}
	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int start, end;
	cin >> start >> end;
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << minimumMulitplications(start, end, arr);
	return 0;
}

