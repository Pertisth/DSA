#include<iostream>
#include<cstring>
using namespace std;


int bruteCount(string l)
{
	int n = l.length();
	return l[0] == l[n - 1];
}

int dp[18][10][10][2];
int solve(string n, int idx, bool flag, int fd, int ld)
{
	if (idx == n.length())
	{
		return fd == ld;
	}

	if (dp[idx][fd][ld][flag] != -1)
	{
		return dp[idx][fd][ld][flag];
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
			if (fd != 0)
			{
				ans = ans + solve(n, idx + 1, true, fd, digit);
			}
			else
			{
				ans = ans + solve(n, idx + 1, true, digit, digit);
			}
		}
		else
		{
			if (fd != 0)
			{
				ans = ans + solve(n, idx + 1, flag, fd, digit);
			}
			else
			{
				ans = ans + solve(n, idx + 1, flag, digit, digit);
			}
		}
	}
	return dp[idx][fd][ld][flag] = ans;
}

int countFirstAndLast(string l, string r)
{
	memset(dp, -1, sizeof(dp));
	int a = solve(r, 0, false, 0, 0);
	memset(dp, -1, sizeof(dp));
	int b = solve(l, 0, false, 0, 0);
	return a - b + bruteCount(l);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string l, r;
	cin >> l >> r;
	cout << countFirstAndLast(l, r);
	return 0;
}