#include<iostream>
#include<vector>
using namespace std;


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
		long long x, y;
		cin >> x >> y;
		y = y * 2;
		x = x + y;

		if (x % 2 == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}