#include<iostream>
#include<queue>
#include<stack>
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
		left = nullptr;
		right = nullptr;
	}
};

Node *createTree()
{
	int ele;
	cin >> ele;
	Node *root = new Node(ele);
	queue<Node*>que;
	que.push(root);
	while (!que.empty())
	{
		int lc;
		int rc;
		Node *curr = que.front();
		que.pop();
		cin >> lc;
		cin >> rc;
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

void inorder(Node *root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

bool findPath(Node *root, vector<int>&path, int n)
{
	if (root == nullptr)
	{
		return false;
	}
	path.push_back(root->data);
	if (root->data == n)
	{
		return true;
	}
	if (findPath(root->left, path, n) || findPath(root->right, path, n))
	{
		return true;
	}
	path.pop_back();
	return false;
}

int LCA(Node *root, int n1, int n2)
{
	vector<int>path1;
	vector<int>path2;
	if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
	{
		return -1;
	}
	int i;
	for (i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++)
	{
		if (path1[i] != path2[i])
		{
			break;
		}
	}
	return path1[i - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = createTree();

	int ans = LCA(root, 9, 0);
	cout << ans;

	return 0;
}