#include<iostream>
#include<unordered_set>
using namespace std;


class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int x)
	{
		this->data = x;
		this->left = nullptr;
		this->right = nullptr;
	}
};


bool pairSum(Node *root, int sum, unordered_set<int>&hash)
{
	if (root == nullptr)
	{
		return false;
	}
	if (pairSum(root->left, sum, hash) == true)
	{
		return true;
	}
	if (hash.find(sum - root->data) != hash.end())
	{
		return true;
	}
	else
	{
		hash.insert(root->data);
	}
	return pairSum(root->right, sum, hash);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(20);
	root->right->left = new Node(16);
	root->right->right = new Node(40);
	int sum = 21;
	unordered_set<int>hash;
	if (pairSum(root, sum, hash))
	{
		cout << "Found ";
	}
	else
	{
		cout << "Not Found";
	}
	return 0;
}