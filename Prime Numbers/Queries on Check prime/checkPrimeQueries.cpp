#include<iostream>
#include<vector>
using namespace std;

int n = 86028121;
vector<bool>prime(n + 1, true);
vector<int>ds;
void createSeive()
{
	for (int i = 2; i * i <= n; i++)
	{
		if (prime[i] == true)
		{
			for (int j = i * i; j <= n; j += i)
			{
				prime[j] = false;
			}
		}
	}
	// check the 5*1000000 prime
	// int limit = 5 * 1000000;
	// int count = 0;
	// int size = 1;
	// for (int i = 2; ; i++)
	// {

	// 	if (prime[i] == true)
	// 	{
	// 		count++;
	// 	}
	// 	if (count == limit)
	// 	{
	// 		size = i;
	// 		break;
	// 	}

	// }
	// cout << size << " ";
	for (int i = 2; i <= n; i++)
	{
		if (prime[i] == true)
		{
			ds.push_back(i);
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	createSeive();
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		cout << ds[k - 1] << endl;
	}
	return 0;
}