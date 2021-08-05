#include<iostream>
#include<vector>
using namespace std;

void findCombinations(int index, vector<int>&arr, int target, vector<int>&ds, vector<vector<int>>&ans)
{
	if (index == arr.size())
	{
		if (target == 0)
		{
			ans.push_back(ds);
		}
		return;
	}

	if (arr[index] <= target)
	{
		ds.push_back(arr[index]);
		findCombinations(index, arr, target - arr[index], ds, ans);
		ds.pop_back();
	}
	findCombinations(index + 1, arr, target, ds, ans);

}

vector<vector<int>> combinationSum(vector<int>&arr, int target, int n)
{
	vector<vector<int>>ans;
	vector<int>ds;
	findCombinations(0, arr, target, ds, ans);
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i] ;
	}
	int target;
	cin >> target;
	vector<vector<int>>ans = combinationSum(arr, target, n);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}