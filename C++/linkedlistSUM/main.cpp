#include <iostream>

using namespace std;

class node
{
public:

    int data;
    node *next;
};
node *head=NULL;

node* create(int x)
{
    node *temp;
    temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;

}

void link(int x)
{
    node *temp;
    temp = create(x);
    if(head==NULL)
    {
        head= temp;
    }
    else
    {
        node *p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
}
int sumoflinkedlist(node *head)
{
    int sum=0;
    node *p=head;
    while(p!=NULL)
    {
        sum = sum + p->data;
        p=p->next;
    }
    return sum;
}

void display(node* head)
{
    node *p=head;
    while(p!=NULL)
    {
        cout << p->data <<"->";
        p=p->next;
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter no.of Nodes : ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int key;
        cin >> key;
        link(key);
    }

    display(head);
    int sum = sumoflinkedlist(head);
    cout << sum;
    return 0;
}
