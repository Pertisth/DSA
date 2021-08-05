#include<iostream>
#include<vector>
using namespace std;



int getSum(vector<int>&st, int qs, int qe, int ss, int se, int si)
{
	if (se < qs || ss > qe)
	{
		return 0;
	}
	if (qs <= ss && qe >= se)
	{
		return st[si];
	}
	int mid = (ss + se) >> 1;

	return getSum(st, qs, qe, ss, mid, 2 * si + 1) + getSum(st, qs, qe, mid + 1, se, 2 * si + 2);
}

int update(vector<int>&st, int idx, int newValue, int ss, int se, int si, vector<int>&arr)
{

	if (idx < ss || idx > se)
	{
		return st[si];
	}

	if (ss == se && ss == idx)
	{
		st[si] = newValue;
		arr[idx] = newValue;
		return st[si];
	}


	int mid = (ss + se) >> 1;
	return st[si] = update(st, idx, newValue, ss, mid, 2 * si + 1, arr) + update(st, idx, newValue, mid + 1, se, 2 * si + 2, arr);
}



// construction of segment tree

int constructSTUtil(int as, int ae, int si, vector<int>&st, vector<int>&arr)
{
	if (as == ae)
	{
		st[si] = arr[as];
		return arr[as];
	}
	int mid = (as + ae) / 2;

	st[si] = constructSTUtil(as, mid, 2 * si + 1, st, arr) + constructSTUtil(mid + 1, ae, 2 * si + 2, st, arr);
	return st[si];

}

void constructST(vector<int>&arr, int n, vector<int>&st)
{
	int aStart = 0;
	int aEnd = n - 1;
	int STindex = 0;
	constructSTUtil(aStart, aEnd, STindex, st, arr);

}

int main()
{
#ifndef ONINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int>st(4 * n, 0);
	constructST(arr, n, st);

	int Q;
	cin >> Q;

	while (Q--)
	{
		int l, r;
		cin >> l >> r;
		cout << getSum(st, l, r, 0, n - 1, 0) << endl;
	}


	// after updating the value
	update(st, 3, 60, 0, n - 1, 0, arr);
	cout << getSum(st, 0, 3, 0, n - 1, 0);


	return 0;
}