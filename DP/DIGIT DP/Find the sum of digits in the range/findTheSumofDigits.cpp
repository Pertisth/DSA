#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

unsigned long long dp[140][15][2];
unsigned long long solve(string &n, int idx, bool flag, unsigned long long sum)
{
	if (idx == n.length())
	{
		return sum;
	}
	if (dp[sum][idx][flag] != -1)
	{
		return dp[sum][idx][flag];
	}
	int limit = n[idx] - '0';
	if (flag)
	{
		limit = 9;
	}
	unsigned long long ans = 0;
	for (int digit = 0; digit <= limit; digit++)
	{
		if (digit < n[idx] - '0')
		{
			ans = ans + solve(n, idx + 1, true, sum + digit);
		}
		else
		{
			ans = ans + solve(n, idx + 1, flag, sum + digit);
		}
	}
	return dp[sum][idx][flag] = ans;
}

unsigned long long sumOfDigits(long long l, long long r)
{

	string str1 = to_string(r);
	string str2 = to_string(l - 1);
	memset(dp, -1, sizeof(dp));
	unsigned long long a = solve(str1, 0, false, 0);
	memset(dp, -1, sizeof(dp));
	unsigned long long b = solve(str2, 0, false, 0);
	return a - b;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		unsigned long long l, r;
		cin >> l >> r;
		cout << sumOfDigits(l, r) << endl;
	}

	return 0;
}