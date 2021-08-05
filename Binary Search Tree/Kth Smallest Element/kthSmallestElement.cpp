#include<iostream>
using namespace std;

class Node {

public:
	int data;
	Node *left;
	Node *right;
	int lcount;
	Node(int x)
	{
		this->data = x;
		this->left = nullptr;
		this->right = nullptr;
		this->lcount = 0;
	}
};

Node *insert(Node *root, int x)
{
	if (root == nullptr)
	{
		return new Node(x);
	}
	else if (x < root->data)
	{
		root->left = insert(root->left, x);
		root->lcount++;
	}
	else if (x > root->data)
	{
		root->right = insert(root->right, x);
	}
	return root;
}

int kthSmallest(Node *root, int k)
{
	if (root == nullptr)
	{
		return -1;
	}
	int count = root->lcount + 1;
	if (count == k)
	{
		return root->data;
	}
	else if (count > k)
	{
		return kthSmallest(root->left, k);
	}
	return kthSmallest(root->right, k - count);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	Node *root = nullptr;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		root = insert(root, ele);
	}
	int k;
	cin >> k;
	cout << kthSmallest(root, k);
	return 0;
}