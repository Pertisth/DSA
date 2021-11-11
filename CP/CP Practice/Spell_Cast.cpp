#include<iostream>
using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t ;
	while (t--)
	{
		int india = 0;
		int england = 0;
		int draw = 0;
		int i = 5;
		while (i--)
		{
			int ele;
			cin >> ele;
			if (ele == 0)
			{
				draw++;
			}
			else if (ele == 1)
			{
				india++;
			}
			else
			{
				england++;
			}
		}
		if (india > england)
		{
			cout << "INDIA" << endl;
		}
		else if (england > india)
		{
			cout << "ENGLAND" << endl;
		}
		else
		{
			cout << "DRAW" << endl;
		}
	}

	return 0;
}
