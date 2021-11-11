#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int bruteOfL(string l, int d, int k)
{
	int count = 0;
	for (int i = 0; i < l.length(); i++)
	{
		if (l[i] - '0' == d)
		{
			count++;
		}
	}
	return (count == k);
}

int dp[18][18][2];
int solve(string n, int idx, bool flag, int cnt, int d, int k)
{
	if (idx == n.length())
	{
		return (cnt == k);
	}

	if (dp[idx][cnt][flag] != -1)
	{
		return dp[idx][cnt][flag];
	}


	int limit = n[idx] - '0';
	if (flag)
	{
		limit = 9;
	}

	int ans = 0;
	for (int digit = 0; digit <= limit; digit++)
	{
		if (digit < n[idx] - '0')
		{
			if (digit == d)
			{
				ans = ans + solve(n, idx + 1, true, cnt + 1, d, k);
			}
			else
			{
				ans = ans + solve(n, idx + 1, true, cnt, d, k);
			}
		}
		// digit == n[idx] ... same number then no liberty
		else
		{
			if (digit == d)
			{
				ans = ans + solve(n, idx + 1, flag, cnt + 1, d, k);
			}
			else
			{
				ans = ans + solve(n, idx + 1, flag, cnt, d, k);
			}
		}
	}
	return dp[idx][cnt][flag] = ans;
}

int countDigitD(string l, string r, int d, int k)
{

	memset(dp, -1, sizeof(dp));
	int a = solve(r, 0, false, 0 , d, k);
	memset(dp, -1, sizeof(dp));
	int b = solve(l, 0, false, 0, d, k);
	return  a - b + bruteOfL(l, d, k);
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string l;
	cin >> l;
	string r;
	cin >> r;
	int d;
	cin >> d;
	int k;
	cin >> k;

	cout << countDigitD(l, r, d, k);
	return 0;
}