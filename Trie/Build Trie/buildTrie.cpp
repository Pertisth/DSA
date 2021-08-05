#include<iostream>
using namespace std;


class Trie {
public:
	Trie *child[26];
	bool isEnd;
	Trie()
	{
		isEnd = false;
		for (int i = 0; i < 26; i++)
		{
			child[i] = nullptr;
		}
	}


};

void insert(Trie *root, string str)
{
	Trie *p = root;
	for (int i = 0; i < str.length(); i++)
	{
		int index = str[i] - 'a';
		if (p->child[index] == nullptr)
		{
			p->child[index] = new Trie();
		}
		p = p->child[index];
	}
	p->isEnd = true;

}

bool search(Trie *root, string key)
{
	Trie *p = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (p->child[index] == nullptr)
		{
			return false;
		}
		p = p->child[index];
	}
	return (p != nullptr && p->isEnd);
}

bool isEmpty(Trie *root)
{
	for (int i = 0; i < 26; i++)
	{
		if (root->child[i] != nullptr)
		{
			return false;
		}
	}
	return true;
}

Trie *delNode(Trie *root, string str, int i)
{
	if (root == nullptr)
	{
		return root;
	}
	if (i == str.length())
	{
		root->isEnd = false;
		if (isEmpty(root))
		{
			delete(root);
			root = nullptr;
		}
		return root;
	}
	int index = str[i] - 'a';
	root->child[index] = delNode(root->child[index], str, i + 1);
	if (isEmpty(root) && root->isEnd == false)
	{
		delete(root);
		root = nullptr;
	}
	return root;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Trie *root = new Trie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		insert(root, str);
	}
	cout << search(root, "bat") << endl;
	delNode(root, "cat", 0);
	cout << search(root, "cat");
	return 0;
}