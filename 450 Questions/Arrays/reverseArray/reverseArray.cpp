#include<iostream>
using namespace std;

void swapNum(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void reverseArr(int arr[], int n)
{
	int i = 0;
	int j = n - 1;
	while (i < j)
	{
		swapNum(arr[i], arr[j]);
		i++;
		j--;
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	reverseArr(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}