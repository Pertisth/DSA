#include<iostream>
#include<queue>
#include<vector>
using namespace std;


void medianOfStream(vector<int>&arr)
{
	int n = arr.size();
	priority_queue<int>first;
	priority_queue<int, vector<int>, greater<int>>second;
	first.push(arr[0]);
	cout << arr[0] << " ";
	for (int i = 1; i < n; i++)
	{
		int val = arr[i];
		if (first.size() > second.size())
		{
			if (val <= first.top())
			{
				second.push(first.top());
				first.pop();
				first.push(val);
			}
			else
			{
				second.push(val);
			}
			cout << (first.top() + second.top()) / 2.0 << " ";
		}
		else
		{
			if (val >= first.top())
			{
				first.push(second.top());
				second.pop();
				second.push(val);
			}
			else
			{
				first.push(val);
			}
			cout << first.top() << " ";
		}
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
	vector<int>arr;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		arr.push_back(ele);
	}
	medianOfStream(arr);
	return 0;
}