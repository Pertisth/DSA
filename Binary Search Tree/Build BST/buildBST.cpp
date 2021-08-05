#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int x)
	{
		data = x;
		left = nullptr;
		right = nullptr;
	}
};


Node* insert(Node *root, int x)
{
	Node *curr = new Node(x);
	if (root == nullptr)
	{
		return curr;
	}
	if (root->data < x)
	{
		root->right = insert(root->right, x);
	}
	else if (root->data > x)
	{
		root->left = insert(root->left, x);
	}
	return root;
}

Node *inorderSucc(Node *root)
{
	root = root->right;
	while (root != nullptr && root->left != nullptr)
	{
		root = root->left;
	}
	return root;
}

Node* deleteNode(Node *root, int x)
{
	if (root == nullptr)
	{
		return root;
	}
	if (root->data < x)
	{
		root->right = deleteNode(root->right, x);
	}
	else if (root->data > x)
	{
		root->left = deleteNode(root->left, x);
	}
	else
	{
		if (root->left == NULL)
		{
			Node *temp = root->right;
			delete(root);
			return temp;
		}
		if (root->right == NULL)
		{
			Node *temp = root->left;
			delete(root);
			return temp;
		}
		else if (root->left && root->right)
		{
			Node *succ = inorderSucc(root);
			root->data = succ->data;
			root->right = deleteNode(root->right, succ->data);
		}

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
	inorder(root);
	cout << "\nAfter deleting 8 : ";
	//root = deleteNode(root, 8);
	root = deleteNode(root, 2);
	inorder(root);



	return 0;
}