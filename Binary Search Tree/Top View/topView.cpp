#include<iostream>
#include<queue>
#include<map>
#include<utility>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int x)
	{
		this->data = x;
		this->left = nullptr;
		this->right = nullptr;
	}
};


void topView(Node *root)
{
	map<int, int>mp;
	queue<pair<Node*, int>>que;
	que.push({root, 0});
	while (!que.empty())
	{
		pair<Node*, int>p = que.front();
		que.pop();
		Node *curr = p.first;
		int hd = p.second;
		if (mp.find(hd) == mp.end())
		{
			mp[hd] = curr->data;
		}

		if (curr->left)
		{
			que.push({curr->left, hd - 1});
		}
		if (curr->right)
		{
			que.push({curr->right, hd + 1});
		}
	}

	for (auto x : mp)
	{
		cout << x.second << " ";
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(50);
	root->left->left = new Node(30);
	root->right->right = new Node(70);
	root->left->right = new Node(40);
	root->right->left = new Node(60);

	// Node *root = new Node(1);
	// root->left = new Node(2);
	// root->right = new Node(3);
	// root->left->right = new Node(4);
	// root->left->right->right = new Node(5);

	topView(root);
	return 0;
}