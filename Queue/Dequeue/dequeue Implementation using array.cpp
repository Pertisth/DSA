#include<bits/stdc++.h>
using namespace std;


class dequeue {
private:
	int *arr;
	int cap;
	int front;
	int size;
public:
	dequeue(int x)
	{
		cap = x;
		arr = new int[cap];
		front = 0;
		size = 0;
	}

	bool isEmpty()
	{
		return (size == 0);
	}
	bool isFull()
	{
		return (size == cap);
	}

	int getFront()
	{
		if (isEmpty())
		{
			return -1;
		}
		else
		{
			return front;
		}
	}

	int getRear()
	{
		if (isFull())
		{
			return -1;
		}
		else
		{
			return (front + size - 1) % cap;
		}
	}

	void insertFront(int x)
	{
		if (isFull())
		{
			cout << "Full" << endl;
			return;
		}
		else
		{
			front = (front + cap - 1) % cap;
			arr[front] = x;
			size++;
			return;
		}
	}
	void insertRear(int x)
	{
		if (isFull())
		{
			cout << "Full" << endl;
			return;
		}
		else
		{
			int rear = getRear();
			rear = (rear + 1) % cap;
			arr[rear] = x;
			size++;
		}
	}

	int deleteFront()
	{
		int val;
		if (isEmpty())
		{
			cout << "Queue Empty";
			return -1;
		}
		else
		{
			val = arr[front];
			front = (front + 1) % cap;
			size--;
		}
		return val;
	}

	int deleteRear()
	{
		int val;
		if (isEmpty())
		{
			cout << "Queue Empty";
			return -1;
		}
		else
		{
			int rear = getRear();
			val = arr[rear];
			size--;
		}
		return val;
	}

};


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	dequeue dq(4);
	dq.insertFront(10);
	dq.insertRear(20);
	dq.insertRear(30);
	cout << dq.deleteFront() << endl;
	cout << dq.deleteRear() << endl;
	return 0;
}