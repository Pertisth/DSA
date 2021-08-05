#include<iostream>
#include<stack>
using namespace std;


int largestRectangleArea(int arr[], int n)
{
	//find prev smaller element
	stack<int>st;
	int prevSmaller[n];
	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && arr[st.top()] >= arr[i])
		{
			st.pop();
		}

		prevSmaller[i] = st.empty() ? 0 : st.top() + 1;
		st.push(i);
	}

	// clear stack to use again
	while (!st.empty())
	{
		st.pop();
	}


	// find next smaller element
	int nextSmaller[n];
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && arr[st.top()] >= arr[i])
		{
			st.pop();
		}
		nextSmaller[i] = st.empty() ? n - 1 : st.top() - 1;
		st.push(i);
	}

	int maxArea = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		int area = (nextSmaller[i] - prevSmaller[i] + 1) * arr[i];
		maxArea = max(maxArea, area);
	}
	return maxArea;
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
	cout << largestRectangleArea(arr, n);
	return 0;
}