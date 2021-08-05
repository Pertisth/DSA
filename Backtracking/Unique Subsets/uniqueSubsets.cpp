#include<iostream>
#include<vector>
#include <set>
#include<algorithm>
using namespace std;

// not optimized
void uniqueSubset(vector<int>&arr, int n, int idx, vector<int>&res, set<vector<int>>&st)
{
	if (idx == n)
	{
		st.insert(res);
		return;
	}
	res.push_back(arr[idx]);
	uniqueSubset(arr, n, idx + 1, res, st);
	res.pop_back();
	uniqueSubset(arr, n, idx + 1, res, st);
}

// optimized
void uniqueSubset(vector<int>&arr, int n, int idx, vector<int>&res, vector<vector<int>>&subsets)
{
	subsets.push_back(res);
	for (int i = idx; i < n; i++)
	{
		if (i != idx && arr[i] == arr[i - 1])
		{
			continue;
		}
		res.push_back(arr[i]);
		uniqueSubset(arr, n, i + 1, res, subsets);
		res.pop_back();
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
	vector<int>res;
	set<vector<int>>st;
	uniqueSubset(arr, n, 0, res, st); // not optimized
	// set<vector<int>>::iterator it;
	// for (it = st.begin(); it != st.end(); it++)
	// {
	// 	vector<int>ans = (*it);
	// 	for (int i = 0; i < ans.size(); i++)
	// 	{
	// 		cout << ans[i] << " ";
	// 	}
	// 	cout << endl;
	// }

	vector<vector<int>>subsets;
	sort(arr.begin(), arr.end());
	uniqueSubset(arr, n, 0, res, subsets);
	for (int i = 0; i < subsets.size(); i++)
	{
		for (int x : subsets[i])
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}