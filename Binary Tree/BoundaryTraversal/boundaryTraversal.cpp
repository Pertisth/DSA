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

void leftSide(Node *root, vector<int>&res)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->left)
	{
		res.push_back(root->data);
		leftSide(root->left, res);
	}
	else if (root->right)
	{
		res.push_back(root->data);
		leftSide(root->right, res);
	}
}

void leafTraversal(Node *root, vector<int>&res)
{
	if (root == nullptr)
	{
		return;
	}
	leafTraversal(root->left, res);
	if (root->left == nullptr && root->right == nullptr)
	{
		res.push_back(root->data);
	}
	leafTraversal(root->right, res);
}

void rightSide(Node *root, vector<int>&res)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->right)
	{
		rightSide(root->right, res);
		res.push_back(root->data);
	}

	else if (root->left)
	{
		rightSide(root->left, res);
		res.push_back(root->data);
	}

}

vector<int> boundaryTraversal(Node *root)
{
	vector<int>res;

	res.push_back(root->data); // root element
	leftSide(root->left, res);
	leafTraversal(root->left, res);
	leafTraversal(root->right, res);
	rightSide(root->right, res);
	return res;

}

vector<int> findSpiral(Node *root)   // using stack and queue
{
	vector<int>res;
	if (root == NULL)
	{
		return res;
	}
	queue<Node*>que;
	stack<Node*>st;
	que.push(root);
	bool reverse = false;
	while (!que.empty())
	{
		reverse = !reverse;
		int count = que.size();
		for (int i = 0; i < count; i++)
		{
			Node *curr = que.front();
			que.pop();
			if (reverse)
			{
				st.push(curr);
			}
			else
			{
				res.push_back(curr->data);
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
		if (reverse)
		{
			while (!st.empty())
			{
				res.push_back(st.top()->data);
				st.pop();
			}
		}
	}
	return res;
}

vector<int> findSpiralStack(Node *root)
{
	stack<Node *>st1;
	stack<Node *>st2;
	vector<int>res;
	if (root == nullptr)
	{
		return res;
	}
	st1.push(root);
	while (!st1.empty() || !st2.empty())
	{
		while (!st1.empty())
		{
			Node *curr = st1.top();
			st1.pop();
			res.push_back(curr->data);
			if (curr->left)
			{
				st2.push(curr->left);
			}
			if (curr->right)
			{
				st2.push(curr->right);
			}
		}
		while (!st2.empty())
		{
			Node *curr = st2.top();
			st2.pop();
			res.push_back(curr->data);
			if (curr->right)
			{
				st1.push(curr->right);
			}
			if (curr->left)
			{
				st1.push(curr->left);
			}
		}
	}
	return res;

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = createTree();
	//inorder(root);
	vector<int>ans = findSpiralStack(root);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}