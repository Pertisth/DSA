#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node *nextRight;
	Node(int x)
	{
		this->data = x;
		left = NULL;
		right = NULL;
		nextRight = NULL;
	}
};

void connect(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	queue<Node*>que;
	que.push(root);
	Node *curr = NULL;
	while (!que.empty())
	{
		int n = que.size();
		for (int i = 0; i < n; i++)
		{
			Node *prev = curr;
			curr = que.front();
			que.pop();

			if (i > 0)
			{
				prev->nextRight = curr;
			}

			if (curr->left)
			{
				que.push(curr->left);
			}
			if (curr->right)
			{
				que.push(curr->right);
			}
		}
		curr->nextRight = NULL;
	}

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
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(60);
	connect(root);
	int a = root->nextRight == NULL ? -1 : root->nextRight->data;
	cout << "nextRight of " << root->data << " is : " << a << endl;

	int b = root->left->nextRight == NULL ? -1 : root->left->nextRight->data;
	cout << "nextRight of " << root->left->data << " is : " << b << endl;

	int c = root->right->nextRight == NULL ? -1 : root->right->nextRight->data;
	cout << "nextRight of " << root->right->data << " is : " << c << endl;

	int d = root->left->left->nextRight == NULL ? -1 : root->left->left->nextRight->data;
	cout << "nextRight of " << root->left->left->data << " is : " << d << endl;

	int e = root->left->right->nextRight == NULL ? -1 : root->left->right->nextRight->data;
	cout << "nextRight of " << root->left->right->data << " is : " << e << endl;
	return 0;
}