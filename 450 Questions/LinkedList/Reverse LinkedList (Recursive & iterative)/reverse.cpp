#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(int x)
	{
		data = x;
		next = nullptr;
	}
};



Node* insertAtEnd(int x, Node *&head, Node *&last)
{
	if (head == nullptr)
	{
		head = new Node(x);
		last = head;
		return head;
	}
	Node *temp = new Node(x);
	last->next = temp;
	last = temp;
	return head;
}

void display(Node *head)
{
	while (head != nullptr)
	{
		cout << head->data << "->";
		head = head->next;
	}
}

Node *reverse(Node *head)   //iterative
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	Node *prev = nullptr;
	while (head != nullptr)
	{
		Node *currNext = head->next;
		head->next = prev;
		prev = head;
		head = currNext;
	}
	return prev;
}

Node *reverseRecursive(Node *head)   // recursive
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	Node *restHead = reverseRecursive(head->next);
	Node *rest_tail = head->next;
	rest_tail->next = head;
	head->next = nullptr;
	return restHead;
}



int main()
{
#ifndef ONLIE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *last = nullptr;
	Node *head = nullptr;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		head = insertAtEnd(ele, head, last);
	}
	cout << "before reversing : ";
	display(head);

	cout << endl;
	cout << "After Reveresal : ";
	head = reverseRecursive(head);
	display(head);
	cout << endl;
	return 0;

}