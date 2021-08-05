#include<iostream>
#include<vector>
using namespace std;

void concatenate(string str)
{
	int startptr = 0;
	int endptr;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ':' && str[i + 1] == ':')
		{
			endptr = i + 2;
			break;
		}
	}

	string res = "";
	while (endptr != str.length())
	{
		if (str[startptr] == ';')
		{
			startptr++;
		}
		res = res + str[startptr];
		res = res + str[endptr];
		startptr++;
		endptr++;
	}
	cout << res << endl;
}


void insertEle(int arr[], int pos, int val)
{
	//5,3,2,7,6,9,8
	int n;
	n = sizeof(arr) / sizeof(arr[0]);
	bool flag = false;
	vector<int>newArr(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		if (i != pos)
		{
			int ele = arr[i];
			newArr.push_back(ele);
			flag = true;
		}
		if (flag)
		{
			newArr.push_back(val);
		}

	}
	for (int i = 0; i < newArr.size(); i++)
	{
		cout << newArr[i] << " ";
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
	int pos;
	cin >> pos;
	int val;
	cin >> val;


	insertEle(arr, pos, val);


	return 0;



}