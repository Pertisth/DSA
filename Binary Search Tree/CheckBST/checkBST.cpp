#include<iostream>
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


Node *insert(Node *root, int x)
{
	if (root == nullptr)
	{
		return new Node(x);
	}
	if (root->data > x)
	{
		root->left = insert(root->left, x);
	}
	else if (root->data < x)
	{
		root->right = insert(root->right, x);
	}
	return root;
}


void inorder(Node *root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}


bool bstCheckUtil(Node *root, int min, int max)
{
	if (root == nullptr)
	{
		return true;
	}
	return ((root->data >= min && root->data <= max) && (bstCheckUtil(root->left, min, root->data)) && (bstCheckUtil(root->right, root->data, max)));
}


bool bstCheck(Node *root)   //efficient
{
	int max = INT_MAX;
	int min = INT_MIN;
	return bstCheckUtil(root, min, max);
}



bool checkBSTUtil(Node *root, int &prev)   // inorder traversal O(n)  efficient
{
	if (root == nullptr)
	{
		return true;
	}
	if (checkBSTUtil(root->left, prev) == false)
	{
		return false;
	}
	if (root->data <= prev)
	{
		return false;
	}
	prev = root->data;
	return checkBSTUtil(root->right, prev);
}

bool checkBST(Node *root)
{
	int prev = INT_MIN;
	return checkBSTUtil(root, prev);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int n;
	// cin >> n;

	Node *root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(30);
	root->right->right = new Node(35);
	root->right->left = new Node(18);
	cout << bstCheck(root);

	return 0;
}