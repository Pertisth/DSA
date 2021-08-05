#include<iostream>
#include<stack>
using namespace std;

class queueFromStack {
	int cap;
	stack<int>input;
	stack<int>output;
	int size;
public:
	queueFromStack(int x)
	{
		this->cap = x;
	}
	void push(int x)
	{
		input.push(x);
	}
	int pop()
	{
		int n;
		if (output.empty() == false)
		{
			n = output.top();
			output.pop();
		}
		else
		{
			while (!input.empty())
			{
				output.push(input.top());
				input.pop();
			}
			n = output.top();
		}
		return n;
	}
	int top()
	{
		if (output.empty() == false)
		{
			return output.top();
		}
		else
		{
			while (!input.empty())
			{
				output.push(input.top());
				input.pop();
			}
		}
		return output.top();
	}
};


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	queueFromStack que(5);
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	que.push(5);

	cout << que.top() << endl;
	cout << "Element removed : " << que.pop() << endl;
	cout << que.top();
	return 0;
}