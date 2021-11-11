#include<iostream>
#include<queue>
#include<stack>
#include<utility>
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

void preInPost(Node* root)
{
	vector<int>pre;
	vector<int>in;
	vector<int>post;
	if (root == NULL)
	{
		return;
	}
	stack<pair<Node*, int>>st;
	Node* node = root;
	st.push({node, 1});
	while (!st.empty())
	{
		auto p = st.top();
		st.pop();
		if (p.second == 1)
		{
			pre.push_back(p.first->data);
			p.second++;
			st.push(p);
			if (p.first->left != NULL)
			{
				st.push({p.first->left, 1});
			}
		}
		else if (p.second == 2)
		{
			in.push_back(p.first->data);
			p.second++;
			st.push(p);
			if (p.first->right != NULL)
			{
				st.push({p.first->right, 1});
			}
		}
		else
		{
			post.push_back(p.first->data);
		}
	}

	cout << " Pre : ";
	for (int i = 0; i < pre.size(); i++)
	{
		cout << pre[i] << " ";
	}
	cout << endl;
	cout << " in : ";
	for (int i = 0; i < in.size(); i++)
	{
		cout << in[i] << " ";
	}
	cout << endl;
	cout << " post : ";
	for (int i = 0; i < post.size(); i++)
	{
		cout << post[i] << " ";
	}
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = createTree();
	preInPost(root);

	return 0;
}