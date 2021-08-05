#include<iostream>
#include<queue>
using namespace std;



// rearrange the word such that no two consecutive characters should be equal;
class freq {
public:
	int key;
	char ch;
	freq(int x, int c)
	{
		key = x;
		ch = c;
	}

};
class myComp {
public:
	bool operator()(freq &a, freq &b)
	{
		return a.key < b.key;
	}
};



string rearrangeCharacters(string str)
{
	priority_queue<freq, vector<freq>, myComp>que;
	int count[26] = {0};
	for (int i = 0; i < str.length(); i++)
	{
		count[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			freq t(count[i], 'a' + i);
			que.push(t);
		}
	}

	string res = "";
	freq prev{ -1, '#'};
	while (!que.empty())
	{
		freq temp = que.top();
		que.pop();
		res = res + temp.ch;

		if (prev.key > 0)
		{
			que.push(prev);
		}

		temp.key--;
		prev = temp;
	}
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
	cout << rearrangeCharacters(str);
	return 0;
}