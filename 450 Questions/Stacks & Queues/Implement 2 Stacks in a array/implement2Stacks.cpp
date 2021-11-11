#include<iostream>
using namespace std;

class Stack {
	int top1;
	int top2;
	int cap;
	int *arr;
public:
	Stack(int x)
	{
		this->cap = x;
		this->top1 = -1;
		this->top2 = cap;
		this->arr = new int[cap];
	}

	void push1(int x)
	{
		if (top1 < top2 - 1)
		{
			top1++;
			arr[top1] = x;
		}
		else
		{
			cout << "Stack 1 overflowed" << endl;
			return ;
		}
	}

	void push2(int x)
	{
		if (top1 < top2 - 1)
		{
			top2--;
			arr[top2] = x;
		}
		else
		{
			cout << "Stack 2 overflowed " << endl;
			return ;
		}
	}

	int pop1()
	{
		if (top1 < 0)
		{
			cout << "Stack 1 underFlowed ";
			return -1;
		}
		int x = arr[top1];
		top1--;
		return x;
	}

	int pop2()
	{
		if (top2 == cap)
		{
			cout << "Stack 2 underFlowed ";
			return -1;
		}
		int x = arr[top2];
		top2++;
		return x;
	}

	int peek1()
	{
		if (top1 < 0)
		{
			cout << "No Elements to peek in stack 1 ";
			return -1;
		}
		return arr[top1];
	}

	int peek2()
	{
		if (top2 == cap)
		{
			cout << "No Elements to peek in stack 2 ";
			return -1;
		}
		return arr[top2];
	}

	bool isEmpty1()
	{
		return top1 == -1;
	}

	bool isEmpty2()
	{
		return top2 == cap;
	}

};


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Stack st(10);
	st.push1(1);
	st.push2(10);
	cout << st.peek1() << endl;
	cout << st.peek2() << endl;
	st.push1(3);
	st.push2(2);
	cout << st.peek1() << endl;
	cout << st.peek2() << endl;
	st.pop1();
	cout << st.peek1() << endl;



	return 0;
}