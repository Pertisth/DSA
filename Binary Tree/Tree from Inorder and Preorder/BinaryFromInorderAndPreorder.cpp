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

Node *createBinaryTree()
{

	int ele;
	cin >> ele;
	Node *root = new Node(ele);
	queue<Node*>que;
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

Node *treeFromPreandInOrder(vector<int>&pre, vector<int>&in, int &preIndex, int inStart, int inEnd)
{
	if (inStart > inEnd)
		return nullptr;

	Node *root = new Node(pre[preIndex++]);

	int inIndex;
	for (int i = inStart; i <= inEnd; i++)
	{
		if (in[i] == root->data)
		{
			inIndex = i;
			break;
		}
	}

	root->left = treeFromPreandInOrder(pre, in, preIndex, inStart, inIndex - 1);
	root->right = treeFromPreandInOrder(pre, in, preIndex, inIndex + 1, inEnd);
	return root;
}

void preorder(Node *root)
{
	if (root != nullptr)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node *root)
{
	if (root != nullptr)
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

	//Node *root = createBinaryTree();
	vector<int>pre{10, 20, 30, 40, 60};
	vector<int>in{10, 30, 20, 40, 60};
	int preIndex = 0;
	Node *root = treeFromPreandInOrder(pre, in, preIndex, 0, 4);
	inorder(root);
	return 0;
}


//in = [10 30 20 40 50 ]
// pre= [10 20 30 40 50 ]