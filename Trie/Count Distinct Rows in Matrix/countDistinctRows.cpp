#include<iostream>
#include<vector>
using namespace std;

class Trie {
public:
	Trie *child[2];
	Trie()
	{
		child[0] = nullptr;
		child[1] = nullptr;
	}
};

bool insert(Trie *root, vector<vector<int>>&mat, int row, int col)
{
	Trie *curr = root;
	bool flag = false;
	for (int i = 0; i < col; i++)
	{
		int index = mat[row][i];
		if (curr->child[index] == nullptr)
		{
			curr->child[index] = new Trie();
			flag = true;
		}
		curr = curr->child[index];
	}
	return flag;
}


int countRows(vector<vector<int>>&mat, int row, int col)
{
	int res = 0;
	Trie *root = new Trie();
	for (int i = 0; i < row; i++)
	{
		if (insert(root, mat, i, col))
		{
			res++;
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
	vector<vector<int>>mat;
	int row;
	cin >> row;
	int col;
	cin >> col;
	for (int i = 0; i < row; i++)
	{
		vector<int>ans;
		for (int j = 0; j < col; j++)
		{
			int a;
			cin >> a;
			ans.push_back(a);
		}
		mat.push_back(ans);
	}

	cout << countRows(mat, row, col);

	return 0;
}