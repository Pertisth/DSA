#include<iostream>
#include<vector>
using namespace std;



int N = 10000000;
int seive[10000001];
void isPrime()
{
	for (int i = 2; i <= N; i++)
	{
		seive[i] = true;
	}
	for (int i = 2; i * i <= N; i++)
	{
		if (seive[i] == true)
		{
			for (int j = i * i; j <= N; j += i)
			{
				seive[j] = false;
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
	isPrime();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (seive[n])
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

}



// int t;
// 	cin >> t;
// 	while (t--)
// 	{
// 		int n;
// 		cin >> n;
// 		if (seive[n])
// 		{
// 			cout << "Yes" << endl;
// 		}
// 		else
// 		{
// 			cout << "No" << endl;
// 		}
// 	}