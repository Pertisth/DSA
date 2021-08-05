#include <iostream>

using namespace std;

class node
{
public:

    node* prev;
    int data;
    node* next;
};
node* head=NULL;
node* last=NULL;

void insert(int x)
{
    node* temp;

    temp = new node;
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        last=temp;
    }
    else
    {
        last->next=temp;
        temp->prev=last;
        last=temp;
    }
}
void printreverse(node* head)
{
    node* p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(p!=NULL)
    {
        cout << p->data <<"->" ;
        p=p->prev;
    }
}

void display(node* head)
{
    node* p=head;
    while(p!=NULL)
    {
        cout << p->data << "->";
        p=p->next;
    }
}
int main()
{
    int n;
    cout << "Enter no of nodes : " ;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int key;
        cout << "Enter the Element : ";
        cin >>key;
        insert(key);
    }
    cout << "Original LL : ";
    display(head);
    cout << endl;
    cout << "Reverse Printing : ";
    printreverse(head);

    return 0;
}
