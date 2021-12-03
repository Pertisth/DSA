#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int x)
	{
		this->data = x;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class maxiInfo {
public:
	int maxNode;
	int minNode;
	int maxSize;
	maxiInfo(int a, int b, int c)
	{
		this->minNode = a;
		this->maxNode = b;
		this->maxSize = c;
	}
};

maxiInfo findMaxBST(Node* root)
{
	if (root == nullptr)
	{
		return maxiInfo(INT_MAX, INT_MIN, 0);
	}
	maxiInfo left = findMaxBST(root->left);
	maxiInfo right = findMaxBST(root->right);
	if (left.maxNode < root->data && root->data < right.minNode)
	{
		int minVal = min(left.minNode, root->data);
		int maxVal = max(right.maxNode, root->data);
		int newSize = left.maxSize + right.maxSize + 1;
		maxiInfo temp = maxiInfo(minVal, maxVal, newSize);
		return temp;
	}
	int maxSize = max(left.maxSize, right.maxSize);
	return maxiInfo(INT_MIN, INT_MAX, maxSize);
}

int maxiBST(Node* root)
{
	return findMaxBST(root).maxSize;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node* root = new Node(20);
	root->left = new Node(15);
	root->right = new Node(40);
	root->left->left = new Node(14);
	root->left->left->right = new Node(17);
	root->left->right = new Node(18);
	root->left->right->left = new Node(16);
	root->left->right->right = new Node(19);
	root->right->left = new Node(30);
	root->right->right = new Node(60);
	root->right->right->left = new Node(50);
	cout << maxiBST(root);
	return 0;
}