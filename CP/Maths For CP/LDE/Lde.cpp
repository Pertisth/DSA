#include<iostream>
using namespace std;


int gcd(int a, int b, int &x, int &y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int g = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return g;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b, c;
	cin >> a >> b >> c;
	int x0, y0;
	int g = gcd(a, b, x0, y0);
	cout << "GCD : " << g << endl;
	cout << "Values of equation are : " << x0*(c / g) << " " << y0*(c / g);
	return 0;
}