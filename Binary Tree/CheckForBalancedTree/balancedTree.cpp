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


// O(N) Solution  returns -1 when not balanced and returns height when balanced
int isBalanced(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int lh = isBalanced(root->left);
	if (lh == -1)
	{
		return -1;
	}
	int rh = isBalanced(root->right);
	if (rh == -1)
	{
		return -1;
	}

	if (abs(lh - rh) > 1)
	{
		return -1;
	}
	else
	{
		max(lh, rh) + 1;
	}
}


// O(N^2)

int height(Node *root)
{
	if (root == nullptr)
	{
		return 0;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	return max(lh, rh) + 1;
}

int checkBalanced(Node *root)
{
	if (root == nullptr)
	{
		return 0;
	}
	int lh = checkBalanced(root->left);
	if (lh == -1)
	{
		return -1;
	}
	int rh = checkBalanced(root->right);
	if (rh == -1)
	{
		return -1;
	}
	if (abs(lh - rh) > 1)
	{
		return -1;
	}
	else
	{
		return max(lh, rh) + 1;
	}

}

// O(N^2)

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = createTree();

	bool ans = checkBalanced(root);
	cout << ans;
	return 0;
}