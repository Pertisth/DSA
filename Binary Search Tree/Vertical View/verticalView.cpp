#include<iostream>
#include<queue>
#include<map>
#include<utility>   // pair
#include<vector>
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

void inorder(Node *root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}


void verticalView(Node *root)
{
	map<int, vector<int>>mp;
	queue<pair<Node*, int>>que;
	que.push({root, 0});
	while (!que.empty())
	{
		pair<Node*, int>p = que.front();
		que.pop();
		Node *curr = p.first;
		int hd = p.second;
		mp[hd].push_back(curr->data);
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
		cout << x.first << ": ";
		vector<int>res = x.second;
		for (auto i : res)
		{
			cout << i << " ";
		}
		cout << endl;
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
	root->right = new Node(30);
	root->right->right = new Node(50);
	root->right->left = new Node(40);

	verticalView(root);

	return 0;
}