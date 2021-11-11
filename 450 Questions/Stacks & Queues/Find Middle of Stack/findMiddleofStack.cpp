#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	int count;
	Node(int x)
	{
		this->data = x;
		this->next = nullptr;
		this->next = nullptr;
		this->count = 0;
	}
};

class stack {
	Node* head;
	Node* mid;
	int size;
public:
	stack()
	{
		head = nullptr;
		mid = nullptr;
		size = 0;
	}

	void push(int x)
	{
		Node* temp = new Node(x);
		temp->next = head;
		if (head != nullptr)
		{
			head->prev = temp;
		}
		size++;
		if (size == 1)
		{
			mid = temp;
		}
		else
		{
			if (size % 2 == 0)
			{
				mid = mid->prev;
			}
		}
		head = temp;
	}

	int pop()
	{
		if (head == nullptr)
		{
			cout << "Stack underflow";
			return -1;
		}
		int res = head->data;
		Node *temp = head;
		size--;
		if (size % 2 != 0)
		{
			mid = mid->next;
		}
		head = head->next;
		if (head)
		{
			head->prev = nullptr;
		}

		delete(temp);
		return res;
	}

	int top()
	{
		if (head == nullptr)
		{
			cout << "No elements at top";
			return -1;
		}
		return head->data;
	}

	int findMid()
	{
		if (head == nullptr)
		{
			cout << "No elements";
			return -1;
		}
		return mid->data;
	}

	void deleteMid()
	{
		Node* midNode = mid;
		mid->next->prev = mid->prev;
		mid->prev->next = mid->next;
		mid = mid->prev;
		delete(midNode);
		size--;
	}

	int isEmpty()
	{
		return head == nullptr;
	}
};



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	cout << "Middle Element : " << st.findMid() << endl;
	st.deleteMid();
	cout << "Middle Element : " << st.findMid() << endl;
	st.pop();
	cout << "Middle Element : " << st.findMid() << endl;
	st.pop();
	cout << "Middle Element : " << st.findMid() << endl;
	st.pop();
	cout << "Middle Element : " << st.findMid() << endl;
	cout << st.pop() << endl;
	cout << st.pop();
	return 0;
}