#include<iostream>
using namespace std;


int shortestContiguousSubstring(string str)
{

}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		cout << shortestContiguousSubstring(str) << endl;
	}
	return 0;
}