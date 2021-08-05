#include<bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int>&q)
{
	if (q.empty())
	{
		return;
	}
	int ele = q.front();
	q.pop();
	reverseQueue(q);
	q.push(ele);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	cout << "Queue before reversing: ";
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	reverseQueue(q);
	cout << "After Reversing Queue: ";
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}