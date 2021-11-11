#include<iostream>
#include<vector>
using namespace std;


class Node {
public:
	int val;
	Node* arr[2];
	Node()
	{
		val = 0;
		arr[0] = nullptr;
		arr[1] = nullptr;
	}
	void insert(int num)
	{
		Node *root = this;
		for (int i = 31; i >= 0; i--)
		{
			bool bitVal = (num & (1 << i));
			if (root->arr[bitVal] == nullptr)
			{
				root->arr[bitVal] = new Node();
			}
			root = root->arr[bitVal];
		}
		root->val = num;
	}

	int findMinXorPair(int num)
	{
		Node *root = this;
		for (int i = 31; i >= 0; i--)
		{
			bool bitVal = (num & (1 << i));
			if (root->arr[bitVal])
			{
				root = root->arr[bitVal];
			}
			else if (root->arr[!bitVal])
			{
				root = root->arr[!bitVal];
			}
		}
		return num ^ root->val;
	}

};




int minXorPair(vector<int>&arr, int n)
{
	Node *root = new Node();
	int minXor = arr[0] ^ arr[1];
	root->insert(arr[0]);
	for (int i = 1; i < n; i++)
	{
		minXor = min(minXor, root->findMinXorPair(arr[i]));
		root->insert(arr[i]);
	}
	return minXor;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n ;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << minXorPair(arr, n);


	return 0;

}