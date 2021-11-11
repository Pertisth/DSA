#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	return (b, a % b);
}


int lcm(int a, int b)
{
	int prod = a * b;
	return prod / gcd(a, b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	cin >> a >> b;
	cout << lcm(a, b);
	return 0;
}