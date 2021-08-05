#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
};
node *head=NULL;
node *last=NULL;
void Insert(int key)
{
    node *temp;

    temp = new node;
    temp->data = key;
    temp->next = NULL;
    if(head==NULL)
    {
        head=temp;
        last=temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}

void DeletingNode(int pos)
{
    node *p,*q;
    p=head;
    if(pos==1)
    {
        p=head;
        head=p->next;
        delete(p);
    }
    else
    {
        for(int i=0;i<pos-1 && p!=NULL;i++)
        {
            q=p;
            p=p->next;
        }
        if(p!=NULL)
        {
            q->next=p->next;
            delete(p);
        }
    }
}

bool checkforsortedLinkedList(node *p)
{

    int num = INT_MIN;
    while(p)
    {
        if(num > p->data)
        {
            return false;
        }
        num=p->data;
        p=p->next;
    }
    return true;
}

void removeduplicates(node *p)
{
    node *q = p->next;
    while(q)
    {
        if(p->data !=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete(q);
            q=p->next;
        }
    }
}

void display(node *head)
{
    node *p=head;
    while(p!=NULL)
    {
        cout << p->data << "->";
        p=p->next;
    }
}

void reverselinkedlist(node *p)
{
    node *q=NULL,*r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;

    }
    head=q;
}

int main()
{
    int n;
    cout << "Enter No.of Nodes : ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int key;
        cin >> key;
        Insert(key);
    }

    cout << "Original LinkedList : ";
    display(head);
    cout << endl;
    /*cout << "Linked List after Deletion : ";
    DeletingNode(5);
    display(head);*/
    /*bool sorted;
    sorted = checkforsortedLinkedList(head);
    if(sorted)
    {
        cout << "List is Sorted";
    }
    else
    {
        cout << "List is Not Sorted";
    }*/
    /*removeduplicates(head);
    cout << "After Removing Duplicates : ";
    display(head);*/
    cout << "After Reversing the LinkedList : ";
    reverselinkedlist(head);
    display(head);
    return 0;
}
