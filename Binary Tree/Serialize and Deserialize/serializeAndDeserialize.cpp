#include<iostream>
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

void serialize(Node *root, vector<int>&arr)
{
	if (root == nullptr)
	{
		arr.push_back(-1);
		return;
	}
	arr.push_back(root->data);
	serialize(root->left, arr);
	serialize(root->right, arr);
}

Node *deserialize(vector<int>&arr, int &index)
{
	if (arr.size() == index)
	{
		return nullptr;
	}
	int val = arr[index];
	index++;
	if (val == -1)
	{
		return nullptr;
	}
	Node *root = new Node(val);
	root->left = deserialize(arr, index);
	root->right = deserialize(arr, index);
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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = new Node(10);
	root->left = new Node(20);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right = new Node(30);
	root->right->right = new Node(60);

	vector<int>arr;
	serialize(root, arr);


	int index = 0;
	Node *newRoot = deserialize(arr, index);
	cout << "Original Tree" << endl;
	inorder(root);
	cout << "Deserialized Tree " << endl;
	inorder(newRoot);
	return 0;

}