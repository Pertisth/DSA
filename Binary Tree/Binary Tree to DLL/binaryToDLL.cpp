#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
	Node *left;
	Node *right;
	int data;
	Node(int x)
	{
		data = x;
		left = nullptr;
		right = nullptr;
	}
};


Node* binaryTree()
{
	queue<Node*>que;
	int ele;
	cin >> ele;
	Node *root = new Node(ele);
	que.push(root);
	while (!que.empty())
	{
		Node *curr = que.front();
		que.pop();
		int lc;
		cin >> lc;
		if (lc != -1)
		{
			curr->left = new Node(lc);
			que.push(curr->left);
		}
		int rc;
		cin >> rc;
		if (rc != -1)
		{
			curr->right = new Node(rc);
			que.push(curr->right);
		}
	}
	return root;
}

Node *binaryToDLLUtil(Node *root, Node *&prev)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	Node *head = binaryToDLLUtil(root->left, prev);
	if (prev == nullptr)
	{
		head = root;
	}
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	binaryToDLLUtil(root->right, prev);
	return head;
}

Node *binaryToDLL(Node *root)
{
	Node *prev = nullptr;
	Node *head = nullptr;
	return binaryToDLLUtil(root, prev);
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

	Node *root = binaryTree();
	Node *head = binaryToDLL(root);


	// checking if it is converted to Doubly Linked List
	Node *last;
	while (head != nullptr)
	{
		if (head->right == nullptr)
		{
			last = head;
		}
		cout << head->data << " -> ";
		head = head->right;
	}
	cout << endl;
	while (last != nullptr)
	{
		cout << last->data << " -> ";
		last = last->left;
	}
	return 0;

}