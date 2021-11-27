#include<iostream>
#include<vector>
using namespace std;

class ST {
private:
	vector<int>st;
public:
	ST(int n)
	{
		st.resize(4 * n + 1);
	}

	void buildMx(int idx, int low, int high, vector<int>&arr)
	{
		if (low == high)
		{
			st[idx] = arr[low];
			return;
		}
		int mid = (low + high) >> 1;
		buildMx(2 * idx + 1, low, mid, arr);
		buildMx(2 * idx + 2, mid + 1, high, arr);
		st[idx] = max(st[2 * idx + 1], st[2 * idx + 2]);
	}

	int searchMx(int idx, int low, int high, int l, int r)
	{
		if (l <= low && r >= high)
		{
			return st[idx];
		}
		else if (high < l || r < low)
		{
			return INT_MIN;
		}
		int mid = (low + high) >> 1;
		return max(searchMx(2 * idx + 1, low, mid, l, r), searchMx(2 * idx + 2, mid + 1, high, l, r));
	}
	void updateMx(int idx, int low, int high, int i, int value, vector<int>&arr)
	{
		if (low == high)
		{
			st[idx] = value;
			arr[i] = value;
			return;
		}
		int mid = (low + high) >> 1;
		if (i <= mid)
		{
			updateMx(2 * idx + 1, low, mid, i, value, arr);
		}
		else
		{
			updateMx(2 * idx + 2, mid + 1, high, i, value, arr);
		}
		st[idx] = max(st[2 * idx + 1], st[2 * idx + 2]);
	}
};

int main()
{
#ifndef ONLINE_JUDGE
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
	ST st(n);
	st.buildMx(0, 0, n - 1, arr);
	int q;
	cin >> q;
	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int l, r;
			cin >> l >> r;
			cout << st.searchMx(0, 0, n - 1, l, r) << endl;
		}
		else
		{
			int i, val;
			cin >> i >> val;
			st.updateMx(0, 0, n - 1, i, val, arr);
		}
	}
	return 0;
}
