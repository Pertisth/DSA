#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


int countSubArrayWithXORK(vector<int>&arr, int k)
{
	int res = 0;
	int xorr = 0;
	unordered_map<int, int>mp;
	for (auto x : arr)
	{
		xorr = xorr ^ x;

		if (xorr == k)
		{
			res++;
		}
		if (mp.find(xorr ^ k) != mp.end())
		{
			res = res + mp[xorr ^ k];
		}
		mp[xorr]++;

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
	int k;
	cin >> k;
	cout << countSubArrayWithXORK(arr, k);

	return 0;
}