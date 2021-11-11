#include<iostream>
using namespace std;

int power(int base, int exp)
{
	int res = 1;
	while (exp != 0)
	{
		if (exp % 2 == 0)
		{
			base = base * base;
			exp = exp / 2;
		}
		else
		{
			res = res * base;
			exp--;
		}
	}
	return res;
}

int pow(int base, int x)
{
	if (x == 0)
	{
		return 1;
	}
	else if (x % 2 == 0)
	{
		return pow(base * base, x / 2);
	}
	return base * pow(base, x - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int base;
	int exp;
	cin >> base >> exp;
	cout << pow(base, exp);
	return 0;
}
