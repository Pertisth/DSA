#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(int key)
    {
        data = key;
        next = NULL;
    }
};

Node *head;
Node *last;

void Insert(int key)
{
    Node *temp = new Node(key);
    if(head == NULL)
    {
        head = temp;
        last = temp;
        return;
    }
    last->next = temp;
    last = last->next;
    return ;

}

void printLL(Node *head)
{
    while(head!=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return;
}

class Stack{
    Node** arr;
    int top = 0;
public:
    Stack()
    {
        arr = new Node*[20];
        top = -1;
    }
    void push(Node *key)
    {
        top++;
        arr[top] = key;
    }
    void pop()
    {
        if(top == -1)
        {
            cout << "No element to pop";
        }
        top--;
    }
    Node* Top()
    {
        return arr[top];
    }
    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        return false;
    }
};

void insertIntoStackAndPrint(Node *head)
{
    Stack st;
    while(head!=NULL)
    {
        st.push(head);
        head = head->next;
    }
    while(!st.isEmpty())
    {
        Node *temp;
        temp = st.Top();
        cout << temp->data;
        st.pop();
    }

}


int main()
{
    head = NULL;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int key;
        cin >> key;
        Insert(key);
    }
    insertIntoStackAndPrint(head);
    //printLL(head);
    return 0;
}
