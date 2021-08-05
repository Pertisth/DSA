#include<iostream>
#include<vector>
#include<stack>
using namespace std;


vector<int> stockSpan(vector<int>&arr, int n)
{

	stack<int>st;
	vector<int>res;  //answer


	st.push(0);
	res.push_back(1);
	for (int i = 1; i < n; i++)
	{
		while (st.empty() == false && arr[st.top()] <= arr[i])
		{
			st.pop();
		}
		int span = st.empty() ? (i + 1) : (i - st.top());
		res.push_back(span);
		st.push(i);
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
	vector<int>arr;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		arr.push_back(ele);
	}

	vector<int>res = stockSpan(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
	}

	return 0;
}
