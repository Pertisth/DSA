#include<iostream>
#include<vector>
using namespace std;

class Node {


public:
	int data;
	Node *left;
	Node *right;
	Node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};



Node* LCA(Node *root, int n1, int n2)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == n1 || root->data == n2)
	{
		return root;
	}
	Node *lca1 = LCA(root->left, n1, n2);
	Node *lca2 = LCA(root->right, n1, n2);
	if (lca1 != NULL && lca2 != NULL)
	{
		return root;
	}
	if (lca1 != NULL)
	{
		return lca1;
	}
	else
	{
		return lca2;
	}
}


void inorder(Node *root)
{
	if (root != NULL)
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

	Node *root = new Node(10);
	root->left = new Node(50);
	root->right = new Node(60);
	root->left->left = new Node(70);
	root->left->left->left = new Node(40);
	root->left->right = new Node(20);
	root->left->right->left = new Node(90);
	root->left->right->left->left = new Node(30);
	root->left->right->right = new Node(80);


	Node *curr = LCA(root, 90, 80);
	if (curr == NULL)
	{
		cout << "No common ancestors " << endl;
	}
	else
	{
		cout << curr->data;
	}

	return 0;



}


