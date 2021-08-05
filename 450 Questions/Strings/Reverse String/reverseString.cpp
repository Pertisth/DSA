#include<iostream>
using namespace std;

void swapStr(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

string reverseString(string str)
{
	int n = str.length();
	int i = 0;
	int j = n - 1;
	while (i < j)
	{
		swapStr(str[i], str[j]);
		i++;
		j--;
	}
	return str;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str;
	cin >> str;
	str = reverseString(str);
	cout << str;
	return 0;
}