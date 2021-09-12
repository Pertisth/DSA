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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int>st(4 * n + 1);
	constructST(arr, n, st);
	while (k--)
	{
		int low, high;
		cin >> low >> high;
		cout << getSum(st, low, high, 0, n - 1, 0) << endl;
	}

	return 0;
}
