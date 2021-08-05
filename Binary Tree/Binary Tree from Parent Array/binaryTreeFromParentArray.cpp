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

void inorder(Node *root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void createNode(vector<int>&parent, vector<Node*>&created, int node, Node* &root)
{
	// if node is already created simply return
	if (created[node] != nullptr)
	{
		return;
	}
	// if node not created earlier , create new node and store in created array
	created[node] = new Node(node);

	// if nodes parent is -1 then we have fuound the root of tree , we assign it to root
	if (parent[node] == -1)
	{
		root = created[node];
		return;
	}

	// check if parent node is created aur not,if not then create recursively

	if (created[parent[node]] == nullptr)
	{
		createNode(parent, created, parent[node], root);
	}

	// check if the created parent node has children ,if not assign accordingly
	Node *p = created[parent[node]];
	if (p->left == nullptr)
	{
		p->left = created[node];
	}
	else
	{
		p->right = created[node];
	}
}

Node* createTree(vector<int>&parent)
{
	Node *root = nullptr;
	vector<Node*>created(parent.size(), nullptr);
	for (int i = 0; i < parent.size(); i++)
	{
		createNode(parent, created, i, root);
	}
	return root;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>parentArr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		parentArr.push_back(ele);
	}
	Node *root = createTree(parentArr);
	inorder(root);
	return 0;

}