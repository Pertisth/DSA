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

bool findPath(Node *root, vector<Node*>&res, int n)
{
	if (root == NULL)
	{
		return false;
	}
	res.push_back(root);
	if (root->data == n)
	{
		return true;
	}
	if (findPath(root->left, res, n) || findPath(root->right, res, n))
	{
		return true;
	}
	res.pop_back();
	return false;
}


Node* LCA(Node *root, int n1, int n2)
{
	vector<Node*>path1;
	vector<Node*>path2;
	if (findPath(root, path1, n1) == false || findPath(root, path2, n2) == false)
	{
		return NULL;
	}
	for (int i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++)
	{
		if (path1[i + 1] != path2[i + 1])
		{
			return path1[i];
		}
	}
	return NULL;

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


