#include<iostream>
#include<stack>
using namespace std;

class Stack {
private:
	int minEle = INT_MAX;
	stack<int>st;
public:
	void myPush(int val)
	{
		if (st.empty())
		{
			st.push(val);
			minEle = val;
		}
		else if (val < minEle)
		{
			int newVal = 2 * val - minEle;
			st.push(newVal);
			minEle = val;
		}
		else
		{
			st.push(val);
		}

	}

	void myPop()
	{
		if (st.empty())
		{
			return;
		}
		int el = st.top();
		st.pop();
		if (el < minEle)
		{
			minEle = 2 * minEle - el;
		}

	}

	int myTop()
	{
		if (st.empty())
		{
			return -1;
		}
		else if (st.top() < minEle)
		{
			return minEle;
		}
		else
		{
			return st.top();
		}
	}
	int getMin()
	{
		return minEle;
	}

};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Stack st;
	st.myPush(-2);
	st.myPush(0);
	st.myPush(-3);
	cout << st.getMin() << endl;
	st.myPop();
	cout << st.myTop() << endl;
	cout << st.getMin() << endl;
	return 0;
}