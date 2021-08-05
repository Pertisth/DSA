#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minPlatforms(vector<int>&arr, vector<int>&dept, int n)
{
	sort(arr.begin(), arr.end());
	sort(dept.begin(), dept.end());

	int min_platforms = 1;
	int count = 1;
	int i = 1;
	int j = 0;
	while (i < n && j < n)
	{
		if (arr[i] <= dept[j])
		{
			count++;
			i++;
		}
		else if (arr[i] > dept[j])
		{
			count--;
			j++;
		}

		if (count > min_platforms)
		{
			min_platforms = count;
		}
	}
	return min_platforms;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>arr{900, 940, 950, 1100, 1500, 1800};
	vector<int>dept{910, 1200, 1120, 1130, 1900, 2000};


	cout << minPlatforms(arr, dept, n);

	return 0;
}