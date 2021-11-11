#include<iostream>
using namespace std;

class queue {
	int *arr;
	int rear;
	int front;
	int cap;
	int size;
public:
	queue(int x)
	{
		this->cap = x;
		this->arr =  new int[cap];
		this->size = 0;
		this->front = 0;
		this->rear = 0;
	}

	void push(int x)
	{
		if (size == cap)
		{
			cout << "Queue Overflow" << endl;
			return ;
		}
		arr[rear % cap] = x;
		size++;
		rear = (rear + 1) % cap;
	}

	int pop()
	{
		if (size == 0)
		{
			cout << "Queue underflow" << endl;
			return -1;
		}
		int x = arr[front];
		front = (front + 1) % cap;
		size--;
		return x;
	}

	int top()
	{
		if (size == 0)
		{
			cout << "No elements in Stack";
			return -1;
		}
		return arr[front];
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
	queue que(5);
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	cout << que.top() << endl;
	cout << que.pop() << endl;
	que.push(4);
	que.push(5);
	que.push(6);
	cout << que.top() << endl;


	return 0;
}