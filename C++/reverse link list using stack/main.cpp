#include <iostream>
#include <stack>

using namespace std;

class node
{
public:
    int data;
    node* next;
};
node* head= NULL;
node* newnode(int key)
{
    node* temp;
    temp = new node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void link(int key)
{
    node* temp;
    temp = newnode(key);
    if(head==NULL)
    {
        head = temp;
    }
    else
    {
        node* p;
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next = temp;
    }
}
void print()
{
    node* temp;
    temp=head;
    while(temp!=NULL)
    {
        cout << "->" << temp->data;
        temp =temp->next;
    }
}

void reverse()
{
    if(head==NULL)
    {
        return;
    }
    stack <node*> s;
    node* temp = head;
    while(temp!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }
    head= s.top();
    temp = head;
    s.pop();
    while(!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp=temp->next;

    }
    temp->next = NULL;

}

int main()
{
    int n;
    cout << "Enter the no of nodes : ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int key;
        cout << "Enter the Key : ";
        cin >> key;

        link(key);
    }
    cout << "Original LinkedList : ";
    print();
    cout << endl;
    cout << "LinkedList After Reversing : ";
    reverse();
    print();
    return 0;
}
