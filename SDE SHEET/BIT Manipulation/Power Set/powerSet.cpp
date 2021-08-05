#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<string> powerSet(string str)
{
	vector<string> res;
	int n = str.length();
	for (int num = 0; num < (1 << n); num++)
	{
		string s = "";
		for (int i = 0; i < n; i++)
		{
			if (num & (1 << i))
			{
				s = s + str[i];
			}
		}
		if (s.size() > 0)
		{
			res.push_back(s);
		}
	}
	sort(res.begin(), res.end());
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string str;
	cin >> str;
	vector<string>res = powerSet(str);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}