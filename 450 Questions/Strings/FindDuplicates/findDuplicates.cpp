#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


void findDup(string str)    //T.C - O(N^2) S.C - O(length of string);
{
	unordered_map<char, bool>umap;

	for (int i = 0; i < str.length(); i++)
	{
		int count = 0;
		char ch = str[i];
		if (umap[ch] == true)
		{
			continue;
		}
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == ch)
			{
				count++;
			}
		}
		if (count > 1)
		{
			cout << ch << " : " << count << endl;
		}
		umap[ch] = true;
	}
}


void findDupEfficicent(string str)   // T.C - O(N)   S.C - O(length of string)
{
	unordered_map<char, int>umap;
	for (int i = 0; i < str.length(); i++)
	{
		umap[str[i]]++;
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (umap[str[i]] > 1)
		{
			cout << str[i] << " : " << umap[str[i]] << endl;
			umap[str[i]] = 0;
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str;
	cin >> str;
	findDupEfficicent(str);
	return 0;
}