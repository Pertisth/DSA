#include<iostream>
#include<vector>
using namespace std;

void bin(long long n, string &str)
{
	if (n > 1)
		bin(n >> 1, str);

	int num = (n & 1);
	string ans = to_string(num);
	str.append(ans);
}

int binaryToDecimal(string &n)
{
	string num = n;
	int dec_value = 0;
	int base = 1;

	int len = num.length();
	for (int i = len - 1; i >= 0; i--) {
		if (num[i] == '1')
			dec_value += base;
		base = base * 2;
	}
	return dec_value;
}

long long findMax(long long a, long long b)
{
	string str1 = "";
	string str2 = "";
	bin(a, str1);
	bin(b, str2);
	int n = str1.length();
	int m = str2.length();
	if (n > m)
	{
		int diff = (abs(n - m));
		while (diff)
		{
			str2.insert(0, "0");
			diff--;
		}
	}
	else if (n < m)
	{
		int diff = (abs(m - n));
		while (diff)
		{
			str1.insert(0, "0");
			diff--;
		}
	}
	int i = 0;
	int j = 0;
	int count = 0;
	while (i < n && j < m)
	{
		if (str1[i] == str2[j])
		{
			if (str1[i] == '0')
			{
				str2[j] = '1';
				count++;
			}
		}
		i++;
		j++;
	}
	j = str2.length() - 1;
	while (count--)
	{
		str2[j] = '0';
		j--;
	}
	long long num1 = binaryToDecimal(str1);
	long long num2 = binaryToDecimal(str2);

	return (num1 | num2);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		long long a, b;
		cin >> a >> b;
		cout << findMax(a, b) << endl;
	}

	return 0;
}