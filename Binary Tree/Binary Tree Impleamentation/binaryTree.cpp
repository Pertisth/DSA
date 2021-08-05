#include<iostream>
#include<queue>
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

Node *createTree()
{
	queue<Node*>que;
	int ele;
	cin >> ele;
	Node *root = new Node(ele);
	que.push(root);
	while (!que.empty())
	{
		int lc, rc;
		cin >> lc;
		cin >> rc;
		Node *curr = que.front();
		que.pop();


		if (lc != -1)
		{
			curr->left = new Node(lc);
			que.push(curr->left);
		}
		if (rc != -1)
		{
			curr->right = new Node(rc);
			que.push(curr->right);
		}
	}
	return root;
}

void preorder(Node *root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = createTree();
	preorder(root);

	return 0;
}