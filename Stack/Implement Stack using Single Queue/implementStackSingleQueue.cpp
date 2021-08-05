#include<iostream>
#include<queue>
using namespace std;

class stackUsingQueue {
	int cap;
	int size;
	queue<int>que;

public:
	stackUsingQueue(int x)
	{
		this->cap = x;
	}
	void push(int x)
	{
		if (cap == size)
		{
			cout << "No more space" << endl;
			return;
		}
		que.push(x);
		int n = que.size();
		for (int i = 0; i < n - 1; i++)
		{
			que.push(que.front());
			que.pop();
		}
		size++;
	}
	int pop()
	{
		int res = que.front();
		que.pop();
		return res;
	}
	int top()
	{
		return que.front();
	}

};


int main()
{
#ifndef ONILNE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	stackUsingQueue st(5);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	cout << st.top();

	return 0;
}