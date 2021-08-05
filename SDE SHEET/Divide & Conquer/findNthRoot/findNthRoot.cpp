#include<iostream>
using namespace std;

double multiply(double number, double n)
{
	double ans = 1.0;
	for (int i = 0; i < n; i++)
	{
		ans = ans * number;
	}
	return ans;
}


double findNthRoot(int n, int m)
{
	double low = 1;
	double high = m;
	double eps = 10e-6;
	while ((high - low) > eps)
	{
		double mid = (low + high) / 2.0;
		if (multiply(mid, n) < m)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}
	return low;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	cout << findNthRoot(n, m);
	return 0;
}