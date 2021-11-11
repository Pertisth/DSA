#include<iostream>
using namespace std;

class stack {
	int *arr;
	int cap;
	int top;
	int size;
public:
	stack(int x)
	{
		this->cap = x;
		arr = new int[cap];
		top = -1;
		size = 0;
	}

	void insert(int x)
	{
		if (size == cap)
		{
			cout << "Stack overflow" << endl;
			return;
		}
		top++;
		arr[top] = x;
		size++;
	}

	int pop()
	{
		if (size == 0)
		{
			cout << "Stack underflow" << endl;
			return -1;
		}
		int x = arr[top];
		top--;
		size--;
		return x;
	}

	int peek()
	{
		if (size == 0)
		{
			cout << "Stack is empty" << endl;
			return -1;
		}
		return arr[top];
	}

	bool isEmpty()
	{
		return size == 0;
	}

};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	stack st(5);
	st.insert(1);
	st.insert(2);
	st.insert(3);
	cout << "Pop : " << st.pop() << endl;
	cout << "Top : " << st.peek() << endl;
	st.insert(3);
	st.insert(4);
	st.insert(5);
	st.insert(6);
	cout << st.peek() << endl;
	return 0;
}