#include<iostream>
using namespace std;

void TOH(int n, char A, char B, char C)
{
	if (n == 0)
	{
		return;
	}
	TOH(n - 1, A, C, B);
	cout << "Move Disk from " << A << " to " << C << endl;
	TOH(n - 1, B, A, C);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	TOH(3, 'A', 'B', 'C');
	return 0;
}