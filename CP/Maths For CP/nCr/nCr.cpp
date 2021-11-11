#include<iostream>
using namespace std;

long long mod = (1e9 + 7);
long long fact[100004];
long long powerPre[100004];


long long power(long long base, long long x)
{
	long long ans = 1;
	while (x != 0)
	{
		if (x % 2 )
		{
			ans = (ans * base) % mod;
			x = x - 1;
		}
		else
		{
			base = (base * base) % mod;
			x = x / 2;
		}
	}
	return ans;
}


void preCompute()
{
	fact[0] = 1;
	for (int i = 1; i <= 10000; i++)
	{
		fact[i] = (i * fact[i - 1]) % mod;
		powerPre[i] = power(fact[i], mod - 2);
	}
}



long long nCr(int n, int r)
{
	long long nume = fact[n];
	long long deno = ((fact[r] % mod) * (fact[n - r] % mod)) % mod;
	long long ans = (nume * power(deno, mod - 2)) % mod;

	return ans;
}

// trick to calculate nCr

// 10c3 ==> (10*9*8)/(1*2*3)

long long trickNcR(int n, int r)
{
	long long ans = 1;
	for (long long i = 1; i <= min(r, n - r); i++)
	{
		ans = ans * (n - i + 1) / i;
	}
	return ans;
}

long long nCrPowerPreComputed(int n, int r)
{
	long long nume = fact[n];
	long long ans = ((nume * powerPre[r]) % mod * powerPre[n - r] % mod) % mod;
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	preCompute();
	int q;
	cin >> q;
	while (q--)
	{
		int n, r;
		cin >> n >> r;
		cout << nCrPowerPreComputed(n, r) << endl;
	}
	return 0;
}