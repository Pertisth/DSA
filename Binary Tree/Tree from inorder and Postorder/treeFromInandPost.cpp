#include<iostream>
#include<vector>
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

int searchEleinInorder(vector<int>in, int data, int startIdx, int endIdx)
{
	int i;
	for (i = startIdx ; i < endIdx; i++)
	{
		if (in[i] == data)
		{
			break;
		}
	}
	return i;
}

Node *treeUtil(vector<int>in, vector<int>post, int &postIdx, int startIdx, int endIdx)
{
	if (startIdx > endIdx)
	{
		return nullptr;
	}
	Node *root = new Node(post[postIdx--]);

	if (startIdx == endIdx)
	{
		return root;
	}
	int idx = searchEleinInorder(in, root->data, startIdx, endIdx);

	root->right = treeUtil(in, post, postIdx, idx + 1, endIdx);
	root->left = treeUtil(in, post, postIdx, startIdx, idx - 1);
	return root;

}

Node *createTree(vector<int>in, vector<int>post)
{
	int postIdx = post.size() - 1;
	return treeUtil(in, post, postIdx, 0, post.size() - 1);
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
#ifndef ONILNE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>in{4, 8, 2, 5, 1, 6, 3, 7};
	vector<int>post{8, 4, 5, 2, 6, 7, 3, 1};

	Node *root = createTree(in, post);
	inorder(root);
	return 0;
}