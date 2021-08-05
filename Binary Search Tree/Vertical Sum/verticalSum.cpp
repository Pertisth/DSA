#include<iostream>
#include<map>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int x)
	{
		this->data = x;
		this->right = nullptr;
		this->left = nullptr;
	}
};


void vSum(Node *root, map<int, int>&mp, int hd)
{
	if (root)
	{
		vSum(root->left, mp, hd - 1);
		mp[hd] = mp[hd] + root->data;
		vSum(root->right, mp, hd + 1);
	}
}


void verticalSum(Node *root)
{
	map<int, int>mp;
	int hd = 0;
	vSum(root, mp, hd);
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
	root->left = new Node(15);
	root->left->left = new Node(35);
	root->left->left->left = new Node(40);
	root->right = new Node(25);
	root->left->right = new Node(20);
	root->left->right->right = new Node(75);
	root->left->right->right->right = new Node(80);
	verticalSum(root);

	return 0;
}