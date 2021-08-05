#include<iostream>
using namespace std;

bool isPrime(int n)
{
	int count = 0;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			count++;
			if (n / i != i)
			{
				count++;
			}
		}
	}

	if (count == 2)
	{
		return true;
	}
	return false;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	cout << isPrime(n);
	return 0;
}