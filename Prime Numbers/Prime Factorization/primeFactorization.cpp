#include<iostream>
using namespace std;


// seive which stores smallest prime factor of the particular number
int N = 1000000;
int arr[1000001];
void createSeive()
{
	for (int i = 0; i <= N; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i * i <= N; i++)
	{
		if (arr[i] == i)
		{
			for (int j = i * i; j <= N; j += i)
			{
				if (arr[j] == j)
				{
					arr[j] = i;
				}
			}
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
		int n;
		cin >> n;
		while (n != 1)
		{
			cout << arr[n] << " ";
			n = n / arr[n];
		}
		cout << endl;
	}
	return 0;
}