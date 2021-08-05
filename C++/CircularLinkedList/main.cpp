#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;
};
node* head=NULL;

void insert(int x)
{
    node* temp;
    node* last;
    temp = new node;
    temp->data = x;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        last=temp;
        temp->next=head;
    }
    else
    {
        last->next=temp;
        last=temp;
        last->next=head;
    }
}

void deleting(int pos)
{
    node* p=head;
    node* q;
    if(pos==1)
    {
       while(p->next!=head)
       {
           p=p->next;
       }
       if(p==head)
       {
           delete(p);
           head=NULL;
       }
       else
       {
           p->next=head->next;
           delete(head);
           head=p->next;
       }
    }
    else
    {
        for(int i=0;i<pos-2;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        delete(q);
    }
}
void display(node* p)
{
    do
    {
        cout << p->data << "->";
        p=p->next;
    }while(p!=head);
}

int main()
{
    int n;
    cout << "Enter no. of nodes : ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int key;
        cin >> key;
        insert(key);
    }
    cout << "Original LinkList : ";
    display(head);
    cout << endl;
    deleting(4);
    display(head);
    return 0;
}


