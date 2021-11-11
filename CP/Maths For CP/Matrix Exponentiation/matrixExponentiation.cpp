#include<iostream>
#include<vector>
using namespace std;

void multiply(vector<vector<int>>&mat1, vector<vector<int>>&mat2)
{
	vector<vector<int>>res(2, vector<int>(2, 0));
	res[0][0] = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
	res[0][1] = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
	res[1][0] = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
	res[1][1] = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			mat1[i][j] = res[i][j];
		}
	}
}

int matrixExpo(int n)
{
	vector<vector<int>>ans{{1, 0}, {0, 1}};
	vector<vector<int>>base{{1, 1}, {1, 0}};

	while (n > 0)
	{
		if (n % 2 == 0)
		{
			multiply(base, base);
			n = n / 2;
		}
		else
		{
			multiply(ans, base);
			n = n - 1;
		}
	}
	return ans[0][0];
}

int nthFibo(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return matrixExpo(n - 1);
}

int sumOfFibo(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return matrixExpo(n + 2) - 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	cout << sumOfFibo(n);
	return 0;
}