#include <iostream>

using namespace std;

 class node
 {
 public:
     int data;
     node *next;
     node *prev;
 };

node *head = NULL;

node *createnode(int key)
{
    node *temp;
    temp = new node();
    temp->data = key;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;

}
void connection(int key)
{
    node *temp;
    temp = createnode(key);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node *p;
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
    }


}
void display()
{
    node *p=head;
    while(p!=NULL)
    {
        cout << "->"<<p->data;
        p=p->next;
    }
}


int main()
{
    int n;
    cout << "Enter the no.of Nodes : ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int key;
        cout << "Enter the Key : ";
        cin >> key;
        connection(key);
    }
    display();

    return 0;
}
