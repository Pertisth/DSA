#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;


class Node {
public:
	int value;
	int arrPos;
	int valPos;
	Node(int a, int b, int c)
	{
		value = a;
		arrPos = b;
		valPos = c;
	}
};


class myComp {
public:
	bool operator()(Node &a, Node &b)
	{
		return a.value > b.value;
	}
};


vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
	vector<int>res;
	priority_queue<Node, vector<Node>, myComp>heap;
	for (int i = 0; i < k; i++)
	{
		Node temp(arr[i][0], i, 0);
		heap.push(temp);
	}
	while (!heap.empty())
	{
		Node temp = heap.top();
		heap.pop();
		int val = temp.value;
		int aPos = temp.arrPos;
		int vPos = temp.valPos;
		res.push_back(val);
		if (vPos + 1 < arr[aPos].size())
		{
			int newValue = arr[aPos][vPos + 1];
			int newArrPos = aPos;
			int newValPos = vPos + 1;
			Node curr(newValue, newArrPos, newValPos);
			heap.push(curr);
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
	vector<vector<int>>arr {
		{1, 2, 3},
		{10, 11, 12},
		{7, 8, 9}
	};
	int k = 3;
	vector<int>res = mergeKSortedArrays(arr, k);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}


	return 0;
}