#include<iostream>
using namespace std;


bool checkPalindrome(string str)
{
	int i = 0;
	int j = str.length() - 1;
	while (i < j)
	{
		if (str[i] == str[j])
		{
			i++;
			j--;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str;
	cin >> str;
	if (checkPalindrome(str))
	{
		cout << "Given string " << str << " : is palindrome";
	}
	else
	{
		cout << "Given string " << str << " : is not palindrome";
	}
	return 0;
}