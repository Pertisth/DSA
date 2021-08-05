#include<bits/stdc++.h>
using namespace std;

// push method costly
class Stack {
private:
	queue<int>que1;
	queue<int>que2;
public:
	int size()
	{
		return que1.size();
	}
	int isEmpty()
	{
		return que1.empty();
	}
	void push(int x)
	{
		while (!que1.empty())
		{
			que2.push(que1.front());
			que1.pop();
		}
		que1.push(x);
		while (!que2.empty())
		{
			que1.push(que2.front());
			que2.pop();
		}
	}
	int pop()
	{
		int ans = que1.front();
		que1.pop();
		return ans;
	}
};



// pop operation costly
class StackP {
private:
	queue<int>que1;
	queue<int>que2;
public:
	void push(int x)
	{
		que1.push(x);
		cout << "Inserting Item : " << x << endl;
	}

	int pop()
	{
		if (que1.empty())
		{
			cout << "No Elements to pop" << endl;
			return -1;
		}
		while (que1.size() != 1)
		{
			que2.push(que1.front());
			que1.pop();
		}
		int ans = que1.front();
		cout << "Popping Element : ";
		que1.pop();
		while (!que2.empty())
		{
			que1.push(que2.front());
			que2.pop();
		}
		return ans;
	}

	int size()
	{
		cout << "Size of Stack : ";
		return que1.size();
	}
	int isEmpty()
	{
		return que1.empty();
	}
	int top()
	{
		while (que1.size() != 1)
		{
			que2.push(que1.front());
			que1.pop();
		}
		int ans = que1.front();
		cout << "Top element in Stack is : ";
		que2.push(ans);
		que1.pop();
		while (!que2.empty())
		{
			que1.push(que2.front());
			que2.pop();
		}
		return ans;
	}

};




int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	StackP st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	cout << st.pop() << endl;
	cout << st.pop() << endl;
	cout << st.size() << endl;
	cout << st.top() << endl;

	return 0;
}