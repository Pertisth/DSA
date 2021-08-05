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





// O(N) Iterative Solution
vector<int> rightViewIterative(Node *root)
{
	queue<Node*>que;
	vector<int>res;
	que.push(root);
	while (!que.empty())
	{
		int count = que.size();

		for (int i = 0; i < count; i++)
		{
			Node *curr = que.front();
			que.pop();
			if (i == count - 1)
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

	}
	return res;
}

// recursive Solution
void rightViewUtil(Node *root, vector<int>&res, int currLevel, int &maxLevel)
{
	if (root == NULL)
	{
		return;
	}
	if (maxLevel < currLevel)
	{
		res.push_back(root->data);
		maxLevel = currLevel;
	}
	rightViewUtil(root->right, res, currLevel + 1, maxLevel);
	rightViewUtil(root->left, res, currLevel + 1, maxLevel);

}
vector<int> rightView(Node *root)
{
	vector<int>res;
	if (root == NULL)
	{
		return res;
	}
	int maxLevel = 0;
	rightViewUtil(root, res, 1, maxLevel);
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = createTree();

	vector<int>res = rightView(root);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}

	return 0;
}